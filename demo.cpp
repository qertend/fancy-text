#include "FancyText.h"

using namespace std;

int main(int argc, char const *argv[]) {
    //FormattedStream Fs;
    FormattedStream Fs(cout, true);

    /*Greedy Fs test*/
    Fs.setBcolor(Magenta);
    Fs.setWeight(Bold);

    //Fs doesn't update until you actually write something to it
    Fs << "";

    Fs << "Greedy = " << Fs.getGreedy() << " FormattedStream test\n";

    Fs.setBcolor(Default);
    Fs.setWeight(Normal);

    /*Control text*/
    Fs << "Normal\n";

    /*Font weights*/
    Fs.setWeight(Bold);
    Fs << "Bold\n";
    Fs.setWeight(Faint);
    Fs<< "Faint\n";
    Fs.setWeight(Normal);

    /*Italic*/
    Fs.setItalic(true);
    Fs << "Italic\n";
    Fs.setItalic(false);
    
    /*Underline*/
    Fs.setUnderline(Single);
    Fs << "Underline(Single)\n";
    Fs.setUnderline(Double);
    Fs << "Underline(Double)\n";
    Fs.setUnderline(NoUnderline);

    /*Overline*/
    Fs.setOverline(true);
    Fs << "Overline\n";
    Fs.setOverline(false);

    /*Blinking*/
    Fs.setBlink(Slow);
    Fs << "Blinking(Slow)\n";
    Fs.setBlink(Rapid);
    Fs << "Blinking(Rapid)\n";
    Fs.setBlink(NoBlink);

    /*Inverted*/
    Fs.setInverted(true);
    Fs << "Inverted\n";
    Fs.setInverted(false);

    /*Invisible*/
    Fs.setInvisible(true);
    Fs << "Invisible\n";
    Fs.setInvisible(false);

    /*Crossed*/
    Fs.setCrossed(true);
    Fs << "Crossed\n";
    Fs.setCrossed(false);

    /*Alternative fonts*/
    for (int i = 0; i < 10; i++) {
        Fs.setFont(i);
        Fs << "Font[" << i << "]\n";
    }
    Fs.setFont(0);

    /*Foreground colors*/
    Fs << "COLORS\nFG-----\n";
    for (int i = Black; i <= Default; i++) {
        int h = Fs.setFcolor(i);
        if (h == -1) cerr << "aw man";
        Fs << "Normal\n";
        Fs.setFcolor(Format::Bright(i));
        Fs << "Bright\n";
    }
    Fs.setFcolor(Default);
    


    /*Background colors*/
    Fs << "BG-----\n";
    for (int i = Black; i <= Default; i++) {
        Fs.setBcolor(i);
        Fs << "Normal\n";

        Fs.setBcolor(Format::Bright(i));
        Fs << "Bright\n"; 
    }

    /*
        TODO: make a demo for the CSI commands
    */

    /*Bell*/
    /**
     * This is horrible, but input buffering is managed by the terminal
     * and I don't know of a universal way to change that
     */
    /*
    Fs << "\nPress Enter to hear the bell\n Enter Q to exit\n";
    char in;
    while (true) {
        in = getchar();
        if (in == 'q' || in == 'Q') break;
        Fs.bell();
    } */
    

    cout << "Exited successfuly\n";
    return 0;
}

/**
 * TODO
 * 256 color support?
 * 
 * as a toggleable option (bool greedy)
 * make formatting more efficient by
 * not resetting the format codes after every write
 * 
 * fix bug where the rest of the line is colored if nl has a background color
 */