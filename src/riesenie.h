#include <stdexcept>

#if !defined( _RIESENIE_H_ )
#define _RIESENIE_H_

class ZString {
    size_t len = 0;
    char *data = nullptr;

public:
    ZString() : ZString("") {};
    ZString(const char *data);

    char operator[](int i) const;

    ZString operator+(ZString obj);

    ZString operator*(int mul);

    void operator+=(ZString obj);

    void operator*=(int mul);

    bool operator<(ZString obj);

    bool operator>(ZString obj);

    bool operator==(ZString obj);

    bool operator<=(ZString obj);

    bool operator>=(ZString obj);

    bool operator!=(ZString obj);

    size_t length();
	char *value();
};

#endif
