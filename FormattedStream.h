#ifndef FormattedStreamH
#define FormattedStreamH

#include "FormattedBuffer.h"
#include <ostream>

//for ED and EL functions
typedef enum {ClearAfter, ClearBefore, ClearAll} EraseType;

class FormattedStream: public FormattedBuffer, public ostream {
    /*the output to manipulate and write to*/
    ostream& display;

    /**
     * used to shorten single parameter CSI instructions by
     * inserting the repetitive part ( \e[ n ) into the stream 
     * */
    ostream& CSIsp(int n);
public:
    //FormattedStream();
    FormattedStream(ostream&);

    void bell();

    /**
     * Moves the cursor n (default 1) cells up.
     * If the cursor is already at the edge of the screen, this has no effect.
     */
    void cursorUp(int n);
    
    /**
     * Moves the cursor n (default 1) cells down.
     * If the cursor is already at the edge of the screen, this has no effect.
     */
    void cursorDown(int n);

    /**
     * Moves the cursor n (default 1) cells right.
     * If the cursor is already at the edge of the screen, this has no effect.
     */
    void cursorRight(int n);

    /**
     * Moves the cursor n (default 1) cells left.
     * If the cursor is already at the edge of the screen, this has no effect.
     */
    void cursorLeft(int n);

    /**
     * Moves cursor to beginning of the line n (default 1) lines down.
     */
    void cursorNL(int n);

    /**
     * Moves cursor to beginning of the line n (default 1) lines up.
     */
    void cursorPL(int n);

    /**
     * Moves the cursor to column n (default 1).
     */
    void cursorHorizontalAbsolute(int n);

    /**
     * Moves the cursor to row r, column c
     * r=1, c=1 is the top left corner
     */
    void cursorPosition(int r, int c);

    /**
     * Clears part of the screen specified by EraseType T
     */
    void eraseInDisplay(EraseType T);

    /**
     * Clears the screen and the scrollback buffer
     */
    void eraseAll();

    /**
     * Clears part of the line specified by EraseType T
     */
    void eraseInLine(EraseType T);

    /**
     * Scroll whole page up by n (default 1) lines.
     * New lines are added at the bottom.
     */
    void scrollUp(int n);

    /**
     * Scroll whole page down by n (default 1) lines.
     * New lines are added at the top.
     */
    void scrollDown(int n);

    /*
        Will maybe add HVP later, not sure rn
    */
};

#endif