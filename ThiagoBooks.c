#include <stdio.h>

void get_text(FILE* f, char out[])
{
    int textmode = 0;
    char ch = 0;
    int i = 0;
    for (; !feof(f); i++)
    {
        ch = fgetc(f);        
        if (ch == '"')
            textmode = textmode ? 0: 1;

        if (ch == ';' && textmode == 0)
            break;

        if (ch == '\n')
        {
            break;
        }
        out[i] = ch;
    }
    out[i] = '\0';
}

int main()
{
    FILE* fo = fopen("out.txt", "w");
    FILE* f = fopen("biblioteca_reserva_petropolis.CSV", "r");
    if (f)
    {
        while (!feof(f))
        {
            char ch = 0;
            int count = 0;

            char title[200] = { 0 };
            get_text(f, title);

            char subtitle[200] = { 0 };
            get_text(f, subtitle);

            char author[200] = { 0 };
            get_text(f, author);

            char ISBN[200] = { 0 };
            get_text(f, ISBN);

            char PublishedDate[20] = { 0 };
            get_text(f, PublishedDate);


            char Length[20];
            get_text(f, Length);

            char Language[20];
            get_text(f, Language);

            char Memo[200];
            get_text(f, Memo);

            char Description[5000];
            get_text(f, Description);

            char Image[200];
            get_text(f, Image);

            printf("%s", ISBN);
            if (title[0] != '\0')
                printf(" | %s", title);
            printf("\n");

            if (title[0] != '\0')
              fprintf(fo, "<h2>%s</h2>\n", title);
            else
                fprintf(fo, "<h2>ISBN:%s</h2>\n", ISBN);

            fprintf(fo, "<img src=\"%s.jpg\"  width=\"260\" height=\"260\">\n", ISBN);
            

            if (Description[0] != '\0')
                fprintf(fo, "<p>%s</p>\n", Description);
            
            
            fprintf(fo, "<p><b>ISBN</b>:%s</p>\n", ISBN);
            if (author[0] != '\0')
              fprintf(fo, "<p><b>Autor</b>:%s</p>\n", author);


            fprintf(fo, "\n");
        }

        fclose(f);
    }
    fclose(fo);
}
