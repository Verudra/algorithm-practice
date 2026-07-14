from __future__ import annotations

import re
from pathlib import Path
from xml.sax.saxutils import escape

from bs4 import BeautifulSoup
from pygments import lex
from pygments.lexers import CppLexer
from pygments.token import Comment, Keyword, Name, Number, Operator, Punctuation, String, Text
from reportlab.lib import colors
from reportlab.lib.enums import TA_CENTER
from reportlab.lib.pagesizes import A4
from reportlab.lib.styles import ParagraphStyle, getSampleStyleSheet
from reportlab.lib.units import mm
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.cidfonts import UnicodeCIDFont
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.platypus import Paragraph, SimpleDocTemplate, Spacer, Table, TableStyle, XPreformatted


ROOT = Path(
    r"C:\Users\Admin（无密码）\WPSDrive\1621728817\WPS企业云盘\中国矿业大学\我的企业文档\algorithm-practice\课程\清华校队练习\gesp"
)
CANDIDATE_DIR = ROOT / "候选" / "3级"

FONT_LATIN = "ConsolasCode"
FONT_CJK = "SimHeiCode"

MONTHS = {
    "2025_3": {
        "title": "CCF GESP 2025年3月认证 C++ 3级",
        "html": CANDIDATE_DIR / "2025_3.html",
        "question_pdf": ROOT / "CCF GESP 2025年3月认证 C++ 3级 纯题目版.pdf",
        "answer_pdf": ROOT / "CCF GESP 2025年3月认证 C++ 3级 答案与解析.pdf",
        "answers": {
            1: "D", 2: "B", 3: "A", 4: "C", 5: "B",
            6: "A", 7: "C", 8: "A", 9: "C", 10: "D",
            11: "D", 12: "A", 13: "C", 14: "D", 15: "C",
            16: "B", 17: "B", 18: "A", 19: "A", 20: "B",
            21: "A", 22: "A", 23: "B", 24: "A", 25: "A",
        },
        "explanations": {
            1: "Base64 每 3 字节变 4 字节，10 字节需要分成 4 组，最终长度是 4×4=16 字节。",
            2: "0xF0 0x90 0x80 0x80 符合 4 字节 UTF-8 的前导位规则；其余选项都不合法。",
            3: "8 位原码中负数最高位为 1，其余位写绝对值 5 的二进制 0000101，所以是 10000101。",
            4: "111 的整数部分是 1101111，小数部分 0.111 对应二进制近似为 .0001110001，所以选 C。",
            5: "补码最核心的作用是统一加减法电路，让有符号整数运算更方便。",
            6: "8 位有符号补码范围是 -128 到 127。",
            7: "把 -5 转成 32 位 unsigned int 会按补码位模式解释，结果是 2^32-5=4294967291。",
            8: "oct 操纵符会让输出按八进制格式显示十进制变量 decimal。",
            9: "输出十六进制应使用 hex，因此是 cout << hex << decimal;",
            10: "^ 是按位异或，不是逻辑运算。",
            11: "枚举找最大值时，若 arr[i] > arr[maxIndex]，就应更新 maxIndex=i。",
            12: "如果要把奇数放前半、偶数放后半，遇到奇数时通常应与前侧位置交换，所以 A 对应的思路正确。",
            13: "在 100 到 999 中，能被 6 整除且十位是个位平方根条件的数量与选项 C 对应。",
            14: "在 HelloC++ 中第 5 位插入 World，之后从下标 5 开始取 5 个字符，得到 World。",
            15: "既是 9 的倍数又不是 8 的倍数，条件应写成 a % 9 == 0 && a % 8 != 0。",
            16: "三角形成立要求任意两边之和都大于第三边，不是只检查一组，所以错。",
            17: "代码判断的是 x & 1，本质就是 ASCII 码奇偶性，和题意一致。",
            18: "闰年条件 ((n%4==0&&n%100!=0)||(n%400==0)) 写法正确。",
            19: "能同时被 3 和 5 整除等价于能被 15 整除，所以判断 n%15==0 正确。",
            20: "从 m 个人中选任意非空子集的方法数是 2^m-1，不是题干所说形式，所以错。",
            21: "2025 的二进制中 1 的个数是偶数，因此按题意属于 A 类数。",
            22: "循环每次输出当前 n 除以 2 的商和余数，再令 n/=2，直到 0，描述正确。",
            23: "13 进制下 A=10、B=11，A+B=21，换成 13 进制应为 18，不是题干表达，所以错。",
            24: "k 进制下各位权值依次是 k^0、k^1、k^2、k^3，题干说法正确。",
            25: "19 进制 CCF = 12×19^2+12×19+15，转成 13 进制正好是 21AC，成立。",
        },
    },
    "2025_6": {
        "title": "CCF GESP 2025年6月认证 C++ 3级",
        "html": CANDIDATE_DIR / "2025_6.html",
        "question_pdf": ROOT / "CCF GESP 2025年6月认证 C++ 3级 纯题目版.pdf",
        "answer_pdf": ROOT / "CCF GESP 2025年6月认证 C++ 3级 答案与解析.pdf",
        "answers": {
            1: "A", 2: "B", 3: "A", 4: "A", 5: "A",
            6: "B", 7: "A", 8: "C", 9: "A", 10: "D",
            11: "B", 12: "B", 13: "D", 14: "B", 15: "C",
            16: "B", 17: "A", 18: "B", 19: "A", 20: "B",
            21: "A", 22: "B", 23: "A", 24: "B", 25: "A",
        },
        "explanations": {
            1: "8 位原码中能表示的最小值是 -127，因为还要保留一位表示符号。",
            2: "反码里正零和负零各一种，所以零共有 2 种表示。",
            3: "10111011 是负数补码，取反加一得到 01000101，也就是 69，所以真值是 -69。",
            4: "00001010 表示十进制 10，除以 2 得 5，补码是 00000101。",
            5: "1101.101 = 8+4+1+0.5+0.125 = 13.625。",
            6: "补码加法中最高位与次高位进位不同，是溢出的判据。",
            7: "35.6(8)=3×8+5+6/8=29.75。",
            8: "1010 | 1100 = 1110。",
            9: "经典异或交换法就是 A 选项。",
            10: "C++ 中正确的一维整型数组定义写法是 int array[5];",
            11: "三位数十位数字应写成 (i / 10) % 10。",
            12: "每次下落先走当前高度，再反弹一半，所以本轮应先累计 distance += height。",
            13: "字符串实际占多少字节取决于采用的编码方式，中文在不同编码下字节数不同。",
            14: "Gesp Test 中最后一个 e 出现在下标 6。",
            15: "Gesp考试 共 6 个字符，字符数和编码字节数不是同一个概念。",
            16: "string 的 == 比较的是内容，不是地址，所以错。",
            17: "substr(1, 3) 表示从下标 1 开始取 3 个字符，描述正确。",
            18: "位移运算不能直接用于浮点数，所以说法错误。",
            19: "string(\"hello\") == \"hello\" 会进行内容比较，结果确实为 true。",
            20: "set 本身已按键有序，迭代器也不是随机访问迭代器，不能直接拿 sort 去排它。",
            21: "(x & 1) == 0 正是判断整数是否为偶数的常用方法。",
            22: "substr 只要起始位置合法，即使长度超界也只是截到末尾，不会因此抛异常。",
            23: "pow 返回浮点值，涉及浮点数时确实可能出现精度问题，所以题干说法成立。",
            24: "枚举的底层类型必须是整型，不能是 float 或 double。",
            25: "如果函数声明为 double f();，实现里 return int; 会自动提升为 double 返回。",
        },
    },
}


def register_fonts():
    pdfmetrics.registerFont(UnicodeCIDFont("STSong-Light"))
    pdfmetrics.registerFont(TTFont(FONT_LATIN, r"C:\Windows\Fonts\consola.ttf"))
    pdfmetrics.registerFont(TTFont(FONT_CJK, r"C:\Windows\Fonts\simhei.ttf"))


def build_styles():
    register_fonts()
    styles = getSampleStyleSheet()
    styles.add(ParagraphStyle(name="ZhTitle", parent=styles["Title"], fontName="STSong-Light", fontSize=22, leading=28, alignment=TA_CENTER, textColor=colors.HexColor("#1f2937")))
    styles.add(ParagraphStyle(name="ZhSubTitle", parent=styles["BodyText"], fontName="STSong-Light", fontSize=11, leading=16, alignment=TA_CENTER, textColor=colors.HexColor("#4b5563")))
    styles.add(ParagraphStyle(name="ZhSection", parent=styles["Heading2"], fontName="STSong-Light", fontSize=16, leading=22, textColor=colors.HexColor("#111827"), spaceBefore=8, spaceAfter=8))
    styles.add(ParagraphStyle(name="ZhQuestion", parent=styles["BodyText"], fontName="STSong-Light", fontSize=11.5, leading=18, textColor=colors.HexColor("#111827"), spaceAfter=5))
    styles.add(ParagraphStyle(name="ZhOption", parent=styles["BodyText"], fontName="STSong-Light", fontSize=11, leading=16, leftIndent=12, textColor=colors.HexColor("#1f2937")))
    styles.add(ParagraphStyle(name="ZhAnswer", parent=styles["BodyText"], fontName="STSong-Light", fontSize=11, leading=18, textColor=colors.HexColor("#111827"), spaceAfter=4))
    styles.add(ParagraphStyle(name="ZhNote", parent=styles["BodyText"], fontName="STSong-Light", fontSize=10, leading=15, textColor=colors.HexColor("#6b7280")))
    styles.add(ParagraphStyle(name="CodeBlock", parent=styles["BodyText"], fontName=FONT_LATIN, fontSize=10, leading=14, textColor=colors.HexColor("#111827")))
    return styles


def footer(canvas, doc):
    canvas.saveState()
    canvas.setStrokeColor(colors.HexColor("#d1d5db"))
    canvas.line(doc.leftMargin, 12 * mm, A4[0] - doc.rightMargin, 12 * mm)
    canvas.setFont("Helvetica", 9)
    canvas.setFillColor(colors.HexColor("#6b7280"))
    canvas.drawRightString(A4[0] - doc.rightMargin, 8 * mm, f"{canvas.getPageNumber()}")
    canvas.restoreState()


def norm(text: str) -> str:
    return " ".join(text.split()).strip()


def get_qnum(text: str) -> int | None:
    m = re.match(r"^第\s*(\d+)\s*题", text)
    return int(m.group(1)) if m else None


def strip_qprefix(text: str) -> str:
    return re.sub(r"^第\s*\d+\s*题\s*", "", text).strip()


def parse_html(path: Path) -> list[dict]:
    html = path.read_text(encoding="utf-8")
    soup = BeautifulSoup(html, "html.parser")
    for node in soup.select(".katex-mathml"):
        node.decompose()
    body = soup.find("div", class_="section__body")
    items = [c for c in body.children if getattr(c, "name", None)]
    questions = []
    section = ""
    i = 0
    while i < len(items):
        node = items[i]
        txt = norm(node.get_text(" ", strip=True))
        if node.name in ("h2", "h3") and txt:
            section = txt
            i += 1
            continue
        num = get_qnum(txt) if node.name == "p" else None
        if num is None:
            i += 1
            continue
        q = {"num": num, "section": section, "stem_parts": [strip_qprefix(txt)], "code": "", "options": []}
        i += 1
        while i < len(items):
            node2 = items[i]
            txt2 = norm(node2.get_text(" ", strip=True))
            if node2.name in ("h2", "h3"):
                break
            if node2.name == "p" and get_qnum(txt2) is not None:
                break
            if node2.name == "div" and "code-toolbar" in (node2.get("class") or []):
                code = node2.find("code")
                if code:
                    q["code"] = code.get_text("\n", strip=False).strip("\n")
            elif node2.name == "p" and txt2:
                q["stem_parts"].append(txt2)
            elif node2.name == "ul":
                q["options"] = [norm(x.get_text(" ", strip=True)) for x in node2.find_all("label")]
            i += 1
        q["stem"] = " ".join(q["stem_parts"])
        del q["stem_parts"]
        questions.append(q)
    return questions


def is_cjk_char(ch: str) -> bool:
    code = ord(ch)
    return (0x3400 <= code <= 0x4DBF) or (0x4E00 <= code <= 0x9FFF) or (0xF900 <= code <= 0xFAFF) or (0x3000 <= code <= 0x303F)


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
    parts = []
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
    markup = []
    for ttype, value in lex(code, CppLexer()):
        color = color_for_token(ttype)
        for segment, font_name in split_by_font(value):
            markup.append(f'<font name="{font_name}" color="{color}">{escape(segment)}</font>')
    return "".join(markup)


def add_code_block(story: list, code: str, styles):
    block = XPreformatted(render_code_markup(code), styles["CodeBlock"])
    story.append(Paragraph('<font color="#94a3b8">代码：</font>', styles["ZhNote"]))
    story.append(block)
    story.append(Spacer(1, 4 * mm))


def build_question_pdf(meta: dict, questions: list[dict], styles):
    doc = SimpleDocTemplate(str(meta["question_pdf"]), pagesize=A4, leftMargin=18 * mm, rightMargin=18 * mm, topMargin=18 * mm, bottomMargin=18 * mm)
    story = [
        Paragraph(meta["title"], styles["ZhTitle"]),
        Spacer(1, 2 * mm),
        Paragraph("纯题目版（不含答案与解析）", styles["ZhSubTitle"]),
        Spacer(1, 2 * mm),
        Paragraph("题面整理自候选目录中的 HTML 内容，仅保留选择题与判断题部分。", styles["ZhNote"]),
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


def build_answer_pdf(meta: dict, questions: list[dict], styles):
    doc = SimpleDocTemplate(str(meta["answer_pdf"]), pagesize=A4, leftMargin=18 * mm, rightMargin=18 * mm, topMargin=18 * mm, bottomMargin=18 * mm)
    answers = meta["answers"]
    single_line = "  ".join(f"{i}-{answers[i]}" for i in range(1, 16))
    judge_line = "  ".join(f"{i}-{answers[i]}" for i in range(16, 26))
    story = [
        Paragraph(meta["title"], styles["ZhTitle"]),
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
        ans = answers[q["num"]]
        story.append(Paragraph(f"第 {q['num']} 题  答案：{ans}  |  {escape(q['stem'])}", styles["ZhQuestion"]))
        story.append(Paragraph(f"解析：{escape(meta['explanations'][q['num']])}", styles["ZhAnswer"]))
        story.append(Spacer(1, 3 * mm))
    doc.build(story, onFirstPage=footer, onLaterPages=footer)


def main():
    styles = build_styles()
    for meta in MONTHS.values():
        questions = parse_html(meta["html"])
        if len(questions) != 25:
            raise RuntimeError(f"{meta['html'].name} 解析到 {len(questions)} 题，不是 25 题")
        build_question_pdf(meta, questions, styles)
        build_answer_pdf(meta, questions, styles)
        print(meta["question_pdf"])
        print(meta["answer_pdf"])


if __name__ == "__main__":
    main()
