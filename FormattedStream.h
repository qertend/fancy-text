#ifndef FormattedStreamH
#define FormattedStreamH

#include "FormattedBuffer.h"
#include <ostream>

//for EiD and EiL functions
typedef enum {ClearAfter, ClearBefore, ClearAll} EraseType;

class FormattedStream: public FormattedBuffer, public std::ostream {
    /*the output to manipulate and write to*/
    std::ostream& display;

public:
    FormattedStream(std::ostream&, bool = false);
    FormattedStream(bool = false);
};

#endif