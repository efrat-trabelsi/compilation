# CPL Lexical Analyzer (CLA)

מנתח לקסיקלי עבור שפת CPL (Compiler Project Language).

## דרישות מערכת
- flex (GNU Flex lexical analyzer generator)
- gcc (GNU Compiler Collection)
- Linux WSL

## הרצת המתרגם

### בנייה והרצה:
```bash
# יצירת קובץ C מקובץ flex
flex cla.lex.txt

# קימפול התוכנית
gcc -o cla lex.yy.c

# הרצת המנתח הלקסיקלי
./cla <filename>.ou
```

### דוגמה:
```bash
flex cla.lex.txt
gcc -o cla lex.yy.c
./cla cpl-test.ou
```

## קבצים

### קבצי מקור:
- `cla.lex.txt` - קובץ הכללים עבור flex

### קבצי בדיקה:
- `cpl-test.ou` - דוגמה לקלט תקין

## פורמט הפלט

הפלט נשמר בקובץ עם סיומת `.tok`:
```
token        lexeme        attribute
-----        ------        ---------
ID           a             a
,	         ,
ID           b             b
:	         :
...
```

## אסימונים נתמכים
- **מילים שמורות:** `break`, `case`, `default`, `else`, `float`, `if`, `input`, `int`, `output`, `switch`, `while`
- **אופרטורים:** `+`, `-`, `*`, `/`, `==`, `!=`, `<`, `>`, `>=`, `<=`, `||`, `&&`, `!`
- **המרות:** `cast<int>`, `cast<float>`
- **מזהים:** אותיות ומספרים המתחילים באות
- **מספרים:** שלמים וממשיים
- **סימבולים:** `()`, `{}`, `,`, `:`, `;`, `=`
- **הערות:** `/* ... */` (ללא קינון)

## ניקוי קבצים
```bash
rm lex.yy.c cla *.tok
```

Author: Efrat Trabelsi
