#include "Format.h"

#include <iostream>
#include <string>


using namespace std;

Format::Format() : fcolor(Default), bcolor(Default+10), weight(Normal),
    underline(NoUnderline), overline(false), blink(NoBlink), font(0),
    italic(false), crossed(false), invisible(false), inverted(false) {}

int Format::setFcolor(int newC) {
    if (newC != fcolor) setUpdateNeeded();
    int prevC = fcolor;
    if ((newC >= Black && newC <= Default) ||
        (newC >= Bright(Black) && newC <= Bright(Default))) {
            fcolor = newC;
            return prevC;
    }

    return -1;
}

int Format::setBcolor(int newC) {
    if (newC != bcolor) setUpdateNeeded();

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
    if (inWeight != weight) setUpdateNeeded();

    FontWeight prev = weight;
    weight = inWeight;
    return prev;
}

Underline Format::setUnderline(Underline inUnder) {
    if (inUnder != underline) setUpdateNeeded();

    Underline prev = underline;
    underline = inUnder;
    return prev;
}

BlinkSpeed Format::setBlink(BlinkSpeed inBlink) {
    if (inBlink != blink) setUpdateNeeded();

    BlinkSpeed prev = blink;
    blink = inBlink;
    return prev;
}

bool Format::setOverline(bool inOverline) {
    if (inOverline != overline) setUpdateNeeded();

    bool prev = overline;
    italic = inOverline;
    return prev;
}

int Format::setFont(int inFont) {
    if (inFont != font) setUpdateNeeded();

    int prev = font;
    if (inFont >= 0 && inFont <= 9) font = inFont;
    else return -1;
    return prev;
}

bool Format::setItalic(bool inItalic) {
    if (inItalic != italic) setUpdateNeeded();

    bool prev = italic;
    italic = inItalic;
    return prev;
}

bool Format::setCrossed(bool inCrossed) {
    if (inCrossed != crossed) setUpdateNeeded();

    bool prev = crossed;
    crossed = inCrossed;
    return prev;    
}

bool Format::setInvisible(bool inInvisible) {
    if (inInvisible != invisible) setUpdateNeeded();

    bool prev = invisible;
    invisible = inInvisible;
    return prev;
}

bool Format::setInverted(bool inInverted) {
    if (inInverted != inverted) setUpdateNeeded();

    bool prev = inverted;
    inverted = inInverted;
    return prev;
}

string Format::getFormatString() const {
    string out;
    char SGR[] = "\e[";
    /*colors*/
    out
        .append(SGR)
        .append(to_string(fcolor)).append(";")
        .append(to_string(bcolor)).append(";")
        /*Font weight*/
        .append(to_string(weight)).append(";")
        /*Underline*/
        .append(to_string(underline)).append(";")
        /*Alternative font*/
        .append(to_string(font + 10)).append(";")
        /*Blinking*/
        .append(to_string(blink)).append("");
    if (italic) out.append(";3");
    if (inverted) out.append(";7");
    if (invisible) out.append(";8");
    if (crossed) out.append(";9");
    if (overline) out.append(";53");

    out.append("m");

    return out;
}

string Format:: getResetString() {
    return string("\e[0m");
}