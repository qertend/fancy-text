#include "Format.h"

#include <iostream>
#include <string>


using namespace std;

Format::Format() : fcolor(Default), bcolor(Default+10), weight(Normal),
    underline(NoUnderline), overline(false), blink(NoBlink), font(0),
    italic(false), crossed(false), invisible(false), inverted(false) {}

int Format::setFcolor(int newC) {
    int prevC = fcolor;
    if ((newC >= Black && newC <= Default) ||
        (newC >= Bright(Black) && newC <= Bright(Default))) {
            fcolor = newC;
            return prevC;
    }

    return -1;
}

int Format::setBcolor(int newC) {
    int prevC = bcolor - 10;

    if ((newC >= Black && newC <= Default) ||
        (newC >= Bright(Black) && newC <= Bright(Default))) {
            bcolor = newC + 10;
            return prevC;
    }

    return -1;
}

int Format::Bright(int col) {
    return col+60;
}

FontWeight Format::setWeight(FontWeight inWeight) {
    FontWeight prev = weight;
    weight = inWeight;
    return prev;
}

Underline Format::setUnderline(Underline inUnder) {
    Underline prev = underline;
    underline = inUnder;
    return prev;
}

BlinkSpeed Format::setBlink(BlinkSpeed inBlink) {
    BlinkSpeed prev = blink;
    blink = inBlink;
    return prev;
}

bool Format::setOverline(bool inOverline) {
    bool prev = overline;
    italic = inOverline;
    return prev;
}

int Format::setFont(int inFont) {
    int prev = font;
    if (inFont >= 0 && inFont <= 9) font = inFont;
    else return -1;
    return prev;
}

bool Format::setItalic(bool inItalic) {
    bool prev = italic;
    italic = inItalic;
    return prev;
}

bool Format::setCrossed(bool inCrossed) {
    bool prev = crossed;
    crossed = inCrossed;
    return prev;    
}

bool Format::setInvisible(bool inInvisible) {
    bool prev = invisible;
    invisible = inInvisible;
    return prev;
}

bool Format::setInverted(bool inInverted) {
    bool prev = inverted;
    inverted = inInverted;
    return prev;
}

string Format::getFormatString() const {
    string out;
    char SGR[] = "\e[";
    /*Colours*/
    out
        .append(SGR)
        .append(to_string(fcolor)).append(";")
        .append(to_string(bcolor)).append("m");
    /*Font weight*/
    out.append(SGR).append(to_string(weight)).append("m");
    /*Underline*/
    out.append(SGR).append(to_string(underline)).append("m");
    /*Alternative font*/
    out.append(SGR).append(to_string(font + 10)).append("m");
    /*Blinking*/
    out.append(SGR).append(to_string(blink)).append("m");
    if (italic) out.append(SGR).append("3m");
    if (inverted) out.append(SGR).append("7m");
    if (invisible) out.append(SGR).append("8m");
    if (crossed) out.append(SGR).append("9m");
    if (overline) out.append(SGR).append("53m");

    return out;
}

string Format:: getResetString() {
    return string("\e[0m");
}