#ifndef FormatH
#define FormatH

#include <iostream>

using namespace std;

/**
 * For bright colours, colour code + 60
 * For background colour, colour code + 10
 */
typedef enum { Black = 30, Red, Green, Yellow, Blue, Magenta, cyan, White, Default } Colour;

typedef enum { Bold = 1, Faint, Normal = 22 } FontWeight;

typedef enum { Slow = 5, Rapid, NoBlink = 25 } BlinkSpeed;

typedef enum { Single = 4, Double = 21, NoUnderline = 24} Underline;

class Format {
    private:
    int fcolor;
    int bcolor;
    FontWeight weight;
    Underline underline;
    bool overline;
    BlinkSpeed blink;
    //add 10 to get font code
    int font;    
    bool italic;
    bool crossed;
    bool invisible;
    //switch foreground and background colours
    bool inverted;
    
    public:
    
    Format();

    static int Bright(int);
    int setFcolor(int);
    int setBcolor(int);
    FontWeight setWeight(FontWeight);
    Underline setUnderline(Underline);
    BlinkSpeed setBlink(BlinkSpeed);
    bool setOverline(bool);
    int setFont(int);
    bool setItalic(bool);
    bool setCrossed(bool);
    bool setInvisible(bool);
    bool setInverted(bool);


    string getFormatString() const;
    static string getResetString();
};

#endif