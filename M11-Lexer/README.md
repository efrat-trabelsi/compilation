# CPL Lexical Analyzer (CLA)

מנתח לקסיקלי עבור שפת CPL (Compiler Project Language).

## דרישות מערכת
- flex (GNU Flex lexical analyzer generator)
- gcc (GNU Compiler Collection)
- Linux/Windows עם MinGW או WSL

## הרצת המתרגם

### שלב 1: יצירת קובץ C מקובץ flex
```bash
flex cla.lex.txt
```

### שלב 2: קימפול התוכנית
```bash
gcc -o cla lex.yy.c
```

### שלב 3: הרצת המנתח הלקסיקלי
```bash
./cla <filename>.ou
```

### דוגמה להרצה מלאה:
```bash
# בנייה
flex cla.lex.txt
gcc -o cla lex.yy.c

# הרצה על קובץ
./cla cpl-program.ou
```

### Windows עם MinGW:
```cmd
flex cla.lex.txt
gcc -o cla.exe lex.yy.c
cla.exe <filename>.ou
```

## קבצים

### קבצי מקור:
- `cla.lex.txt` - קובץ הכללים עבור flex

### קבצי בדיקה:
- `test.ou` - דוגמה לקלט תקין
- `error_test.ou` - דוגמה עם שגיאות לקסיקליות
- `cpl-program.ou` - דוגמה נוספת לקלט

### קבצי ביניים שנוצרים:
- `lex.yy.c` - קובץ C שנוצר על ידי flex
- `cla` - קובץ הרצה מקומפל (Linux/WSL)
- `cla.exe` - קובץ הרצה מקומפל (Windows)

## פורמט הפלט

הפלט נשמר בקובץ עם סיומת `.tok` ומכיל:
```
token        lexeme        attribute
-----        ------        ---------
ID           a             a
COMMA        ,
ID           b             b
COLON        :
...
```

## טיפול בשגיאות

- שגיאות לקסיקליות מודפסות ל-stderr עם מספר שורה
- המנתח ממשיך לאחר שגיאה כדי לזהות שגיאות נוספות
- אין יצירת קובץ פלט במקרה של שגיאת ממשק

## מאפיינים

### אסימונים נתמכים:
- מילים שמורות: `break`, `case`, `default`, `else`, `float`, `if`, `input`, `int`, `output`, `switch`, `while`
- אופרטורים: `+`, `-`, `*`, `/`, `==`, `!=`, `<`, `>`, `>=`, `<=`, `||`, `&&`, `!`
- המרות: `cast<int>`, `cast<float>`
- מזהים: אותיות ומספרים המתחילים באות
- מספרים: שלמים וממשיים
- סימבולים: `()`, `{}`, `,`, `:`, `;`, `=`

### טיפול בהערות:
- הערות של סוג `/* ... */` מתעלמות מהן
- ללא קינון של הערות

### דוגמה מלאה להרצה:
```bash
# בנייה של המנתח
flex cla.lex.txt
gcc -o cla lex.yy.c

# הרצה על קובץ תקין
./cla test.ou

# הצגת תוכן הפלט
cat test.tok

# הרצה על קובץ עם שגיאות
./cla error_test.ou
```

## ניקוי קבצים
```bash
# הסרת קבצי ביניים
rm lex.yy.c cla

# הסרת קבצי פלט
rm *.tok
```

מחבר: [שם הסטודנט]
