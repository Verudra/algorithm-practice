from __future__ import annotations

import re
from pathlib import Path
from xml.sax.saxutils import escape

from bs4 import BeautifulSoup
from pygments import lex
from pygments.lexers import CppLexer
from pygments.token import Comment, Keyword, Name, Number, Operator, Punctuation, String, Text, Token
from reportlab.lib import colors
from reportlab.lib.enums import TA_CENTER
from reportlab.lib.pagesizes import A4
from reportlab.lib.styles import ParagraphStyle, getSampleStyleSheet
from reportlab.lib.units import mm
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.cidfonts import UnicodeCIDFont
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.platypus import (
    Paragraph,
    SimpleDocTemplate,
    Spacer,
    Table,
    TableStyle,
    XPreformatted,
)


ATTACHMENT = Path(
    r"C:\Users\Admin（无密码）\.codex\attachments\654cea91-ac40-4b7e-b6b4-5d20d4a0da7a\pasted-text.txt"
)
OUT_DIR = Path(
    r"C:\Users\Admin（无密码）\WPSDrive\1621728817\WPS企业云盘\中国矿业大学\我的企业文档\algorithm-practice\课程\清华校队练习\gesp"
)
QUESTION_PDF = OUT_DIR / "CCF GESP 2025年9月认证 C++ 3级 纯题目版.pdf"
ANSWER_PDF = OUT_DIR / "CCF GESP 2025年9月认证 C++ 3级 答案与解析.pdf"

FONT_LATIN = "ConsolasCode"
FONT_CJK = "SimHeiCode"


ANSWER_MAP = {
    1: "C",
    2: "C",
    3: "D",
    4: "B",
    5: "B",
    6: "B",
    7: "B",
    8: "D",
    9: "A",
    10: "C",
    11: "D",
    12: "C",
    13: "D",
    14: "C",
    15: "D",
    16: "A",
    17: "A",
    18: "A",
    19: "A",
    20: "B",
    21: "B",
    22: "B",
    23: "B",
    24: "B",
    25: "B",
}


EXPLANATIONS = {
    1: "a 和 b 都是 int，a / b 先做整型除法得到 3，再赋值给 double，因此结果是 3.0。",
    2: "A、B、D 都是 false，只有 (10 != 10) || (5 >= 3) 中后半句为 true，所以整个表达式为 true。",
    3: "长度为 5 的数组下标范围是 0 到 4，arr[5] 已经越界，不能访问最后一个元素。",
    4: "循环中 i 依次取 1、3、5，外层 sum 累加得到 9；花括号里的 int sum = 0 是新的局部变量，不影响外层 sum。",
    5: "返回较大值的函数应有返回类型 int，参数也要写出类型，B 的写法完整且正确。",
    6: "arr[3] = arr[0] + arr[2] = 1 + 3 = 4，所以数组变为 {1, 2, 3, 4}。",
    7: "函数确实只能通过 return 直接返回一个值，但可以借助引用、指针、结构体等方式间接带回多个结果。",
    8: "continue 会直接进入下一轮循环，count++ 永远执行不到，所以执行次数是 0。",
    9: "外层 i 从 0 到 3，内层每次输出 0 到 i，结果正好是 0#01#012#0123#。",
    10: "for 中声明的变量作用域不只是在循环体内，还包括整个 for 语句的条件和更新部分，所以 A 的说法不准确。",
    11: "把 2147483647 反转会溢出，而 1463847412 反转后是 2147483641，仍在 32 位 int 的范围内。",
    12: "找最大值时应先把 maxVal 初始化为第一个元素 arr[0]，再从后续元素开始比较。",
    13: "现代 C++ 不允许省略函数返回类型并默认成 int，因此 D 正确；其余说法都不符合 C++ 规则。",
    14: "共有 2 处越界：for 循环里 i <= SIZE 会写到 arr[5]，后面的 arr[SIZE] 读取也同样越界。",
    15: "string 可以直接用 == 比较内容，但 char 数组名比较的是地址，不会自动比较字符串内容。",
    16: "按标准 C++，普通字符字面量 'a' 的类型是 char，而 sizeof(char) 按定义就是 1，所以这句话应判正确。",
    17: "全局变量和静态存储期对象如果没有显式初始化，会被自动零初始化。",
    18: "do...while 是先执行循环体再判断条件，所以即使条件是 false，也至少会执行 1 次。",
    19: "前置 ++i 的结果仍指向原对象，可作为左值；后置 i++ 产生的是修改前的临时值，属于右值。",
    20: "RED 是未限定枚举 Color 的枚举值，类型属于该枚举类型，不是 int，只是可以隐式转换为 int。",
    21: "宏没有给参数和整体加括号，SQUARE(2+3) 会展开成 2+3*2+3，结果是 11，不安全。",
    22: "char 是否有符号由实现决定，常见范围可能是 -128 到 127，也可能是 0 到 255，不能说总是如此。",
    23: "只有当 a 和 b 都是同类型的可修改左值时，这个条件表达式才能作为赋值左侧；题目说成“一定合法”不成立。",
    24: "#include \"file.h\" 通常会先查当前目录，再查系统目录；#include <file.h> 则优先按系统头文件规则查找，策略并不完全相同。",
    25: "extern 是声明，不等于可以多次定义；同一个变量的定义仍然不能在同一作用域里重复出现。",
}


def normalize_text(text: str) -> str:
    text = text.replace("\xa0", " ")
    text = re.sub(r"\s+", " ", text)
    return text.strip()


def normalize_code(text: str) -> str:
    text = text.replace("\r\n", "\n").replace("\r", "\n")
    text = text.replace("\xa0", " ")
    text = text.replace("，", ",")
    lines = [line.rstrip() for line in text.split("\n")]
    return "\n".join(lines).strip()


def parse_questions() -> list[dict]:
    html = ATTACHMENT.read_text(encoding="utf-8")
    soup = BeautifulSoup(html, "html.parser")
    for node in soup.select(".katex-mathml"):
        node.decompose()

    container = soup.find("div", class_="section__body")
    questions: list[dict] = []
    current = None
    section = ""

    for child in container.children:
        if not getattr(child, "name", None):
            continue

        if child.name == "h3":
            section = normalize_text(child.get_text(" ", strip=True))
            continue

        if child.name == "ol":
            start = int(child.get("start", len(questions) + 1))
            items = child.find_all("li", recursive=False)
            for offset, li in enumerate(items):
                current = {
                    "num": start + offset,
                    "section": section,
                    "stem": normalize_text(li.get_text(" ", strip=True)),
                    "code": "",
                    "options": [],
                }
                questions.append(current)
            continue

        if current is None:
            continue

        if child.name == "div" and "code-toolbar" in (child.get("class") or []):
            code = child.find("code")
            if code:
                current["code"] = normalize_code(code.get_text())
            continue

        if child.name == "ul":
            labels = child.find_all("label")
            current["options"] = [normalize_text(label.get_text(" ", strip=True)) for label in labels]

    return questions


def register_fonts():
    pdfmetrics.registerFont(UnicodeCIDFont("STSong-Light"))
    pdfmetrics.registerFont(TTFont(FONT_LATIN, r"C:\Windows\Fonts\consola.ttf"))
    pdfmetrics.registerFont(TTFont(FONT_CJK, r"C:\Windows\Fonts\simhei.ttf"))


def build_styles():
    register_fonts()
    styles = getSampleStyleSheet()
    styles.add(
        ParagraphStyle(
            name="ZhTitle",
            parent=styles["Title"],
            fontName="STSong-Light",
            fontSize=22,
            leading=28,
            alignment=TA_CENTER,
            textColor=colors.HexColor("#1f2937"),
        )
    )
    styles.add(
        ParagraphStyle(
            name="ZhSubTitle",
            parent=styles["BodyText"],
            fontName="STSong-Light",
            fontSize=11,
            leading=16,
            alignment=TA_CENTER,
            textColor=colors.HexColor("#4b5563"),
        )
    )
    styles.add(
        ParagraphStyle(
            name="ZhSection",
            parent=styles["Heading2"],
            fontName="STSong-Light",
            fontSize=16,
            leading=22,
            textColor=colors.HexColor("#111827"),
            spaceBefore=8,
            spaceAfter=8,
        )
    )
    styles.add(
        ParagraphStyle(
            name="ZhQuestion",
            parent=styles["BodyText"],
            fontName="STSong-Light",
            fontSize=11.5,
            leading=18,
            textColor=colors.HexColor("#111827"),
            spaceAfter=5,
        )
    )
    styles.add(
        ParagraphStyle(
            name="ZhOption",
            parent=styles["BodyText"],
            fontName="STSong-Light",
            fontSize=11,
            leading=16,
            leftIndent=12,
            textColor=colors.HexColor("#1f2937"),
        )
    )
    styles.add(
        ParagraphStyle(
            name="ZhAnswer",
            parent=styles["BodyText"],
            fontName="STSong-Light",
            fontSize=11,
            leading=18,
            textColor=colors.HexColor("#111827"),
            spaceAfter=4,
        )
    )
    styles.add(
        ParagraphStyle(
            name="ZhNote",
            parent=styles["BodyText"],
            fontName="STSong-Light",
            fontSize=10,
            leading=15,
            textColor=colors.HexColor("#6b7280"),
        )
    )
    styles.add(
        ParagraphStyle(
            name="CodeBlock",
            parent=styles["BodyText"],
            fontName=FONT_LATIN,
            fontSize=10,
            leading=14,
            textColor=colors.HexColor("#111827"),
        )
    )
    return styles


def footer(canvas, doc):
    canvas.saveState()
    canvas.setStrokeColor(colors.HexColor("#d1d5db"))
    canvas.line(doc.leftMargin, 12 * mm, A4[0] - doc.rightMargin, 12 * mm)
    canvas.setFont("Helvetica", 9)
    canvas.setFillColor(colors.HexColor("#6b7280"))
    canvas.drawRightString(A4[0] - doc.rightMargin, 8 * mm, f"{canvas.getPageNumber()}")
    canvas.restoreState()


def is_cjk_char(ch: str) -> bool:
    code = ord(ch)
    return (
        0x3400 <= code <= 0x4DBF
        or 0x4E00 <= code <= 0x9FFF
        or 0xF900 <= code <= 0xFAFF
        or 0x3000 <= code <= 0x303F
    )


def font_for_text(text: str) -> str:
    return FONT_CJK if any(is_cjk_char(ch) for ch in text) else FONT_LATIN


def color_for_token(ttype) -> str:
    if ttype in Comment:
        return "#2f855a"
    if ttype in Keyword:
        return "#2563eb"
    if ttype in Name.Function:
        return "#0f766e"
    if ttype in Name.Builtin or ttype in Name.Class:
        return "#7c3aed"
    if ttype in String:
        return "#b91c1c"
    if ttype in Number:
        return "#b45309"
    if ttype in Operator:
        return "#be123c"
    if ttype in Punctuation:
        return "#475569"
    if ttype in Text:
        return "#111827"
    return "#111827"


def split_by_font(text: str) -> list[tuple[str, str]]:
    if not text:
        return []
    parts: list[tuple[str, str]] = []
    buf = [text[0]]
    current_font = font_for_text(text[0])
    for ch in text[1:]:
        nxt_font = font_for_text(ch)
        if nxt_font == current_font:
            buf.append(ch)
        else:
            parts.append(("".join(buf), current_font))
            buf = [ch]
            current_font = nxt_font
    parts.append(("".join(buf), current_font))
    return parts


def render_code_markup(code: str) -> str:
    markup: list[str] = []
    for ttype, value in lex(code, CppLexer()):
        color = color_for_token(ttype)
        for segment, font_name in split_by_font(value):
            markup.append(
                f'<font name="{font_name}" color="{color}">{escape(segment)}</font>'
            )
    return "".join(markup)


def add_code_block(story: list, code: str, styles):
    code_markup = render_code_markup(code)
    block = XPreformatted(code_markup, styles["CodeBlock"])
    box = Table([[block]], colWidths=[170 * mm])
    box.setStyle(
        TableStyle(
            [
                ("BACKGROUND", (0, 0), (-1, -1), colors.HexColor("#f8fafc")),
                ("BOX", (0, 0), (-1, -1), 0.6, colors.HexColor("#cbd5e1")),
                ("LEFTPADDING", (0, 0), (-1, -1), 9),
                ("RIGHTPADDING", (0, 0), (-1, -1), 9),
                ("TOPPADDING", (0, 0), (-1, -1), 8),
                ("BOTTOMPADDING", (0, 0), (-1, -1), 8),
            ]
        )
    )
    story.append(box)
    story.append(Spacer(1, 4 * mm))


def build_question_pdf(questions: list[dict], styles):
    doc = SimpleDocTemplate(
        str(QUESTION_PDF),
        pagesize=A4,
        leftMargin=18 * mm,
        rightMargin=18 * mm,
        topMargin=18 * mm,
        bottomMargin=18 * mm,
    )

    story = [
        Paragraph("CCF GESP 2025年9月认证 C++ 3级", styles["ZhTitle"]),
        Spacer(1, 2 * mm),
        Paragraph("纯题目版（不含答案与解析）", styles["ZhSubTitle"]),
        Spacer(1, 2 * mm),
        Paragraph("题面整理自你提供的网页内容，仅保留选择题与判断题部分。", styles["ZhNote"]),
        Spacer(1, 8 * mm),
    ]

    current_section = None
    for q in questions:
        if q["section"] != current_section:
            current_section = q["section"]
            story.append(Paragraph(escape(current_section), styles["ZhSection"]))

        story.append(Paragraph(f"第 {q['num']} 题  {escape(q['stem'])}", styles["ZhQuestion"]))
        if q["code"]:
            add_code_block(story, q["code"], styles)
        for opt in q["options"]:
            story.append(Paragraph(escape(opt), styles["ZhOption"]))
        story.append(Spacer(1, 4 * mm))

    doc.build(story, onFirstPage=footer, onLaterPages=footer)


def build_answer_pdf(questions: list[dict], styles):
    doc = SimpleDocTemplate(
        str(ANSWER_PDF),
        pagesize=A4,
        leftMargin=18 * mm,
        rightMargin=18 * mm,
        topMargin=18 * mm,
        bottomMargin=18 * mm,
    )

    single_line = "  ".join(f"{i}-{ANSWER_MAP[i]}" for i in range(1, 16))
    judge_line = "  ".join(f"{i}-{ANSWER_MAP[i]}" for i in range(16, 26))

    story = [
        Paragraph("CCF GESP 2025年9月认证 C++ 3级", styles["ZhTitle"]),
        Spacer(1, 2 * mm),
        Paragraph("答案与解析（与题目版分离）", styles["ZhSubTitle"]),
        Spacer(1, 6 * mm),
        Paragraph("选择题答案总表", styles["ZhSection"]),
        Paragraph(escape(single_line), styles["ZhAnswer"]),
        Spacer(1, 2 * mm),
        Paragraph("判断题答案总表", styles["ZhSection"]),
        Paragraph(escape(judge_line), styles["ZhAnswer"]),
        Spacer(1, 3 * mm),
        Paragraph("判断题中 A 表示“正确”，B 表示“错误”。", styles["ZhNote"]),
        Spacer(1, 8 * mm),
    ]

    current_section = None
    for q in questions:
        if q["section"] != current_section:
            current_section = q["section"]
            story.append(Paragraph(escape(current_section), styles["ZhSection"]))

        ans = ANSWER_MAP[q["num"]]
        story.append(
            Paragraph(
                f"第 {q['num']} 题  答案：{ans}  |  {escape(q['stem'])}",
                styles["ZhQuestion"],
            )
        )
        story.append(Paragraph(f"解析：{escape(EXPLANATIONS[q['num']])}", styles["ZhAnswer"]))
        story.append(Spacer(1, 3 * mm))

    story.append(Spacer(1, 4 * mm))
    story.append(
        Paragraph(
            "注：第 16 题按标准 C++ 规则给出解析；若某些资料沿用 C 语言字符常量习惯，可能会出现不同标注。",
            styles["ZhNote"],
        )
    )

    doc.build(story, onFirstPage=footer, onLaterPages=footer)


def main():
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    questions = parse_questions()
    styles = build_styles()
    build_question_pdf(questions, styles)
    build_answer_pdf(questions, styles)
    print(QUESTION_PDF)
    print(ANSWER_PDF)
    print(f"questions={len(questions)}")


if __name__ == "__main__":
    main()
