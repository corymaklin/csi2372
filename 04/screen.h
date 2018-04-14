#ifndef SCREEN_H
#define SCREEN_H

static const int g_width = 40;
static const int g_height = 20;

void printScreen(char(&screen)[g_height][g_width]);
void clearScreen(char(&screen)[g_height][g_width]);
void gridScreen(char(&screen)[g_height][g_width], int hline, int vline);

class screen
{
    public:
        screen();
    protected:
    private:
};

#endif // SCREEN_H
