#include <initializer_list>
 
namespace std {
 
    // character traits:
    template<class charT> struct char_traits;
    template <> struct char_traits<char>;
    template <> struct char_traits<char16_t>;
    template <> struct char_traits<char32_t>;
    template <> struct char_traits<wchar_t>;
 
    // basic_string:
    template<class charT, class traits = char_traits<charT>,
        class Allocator = allocator<charT> >
            class basic_string;
 
    template<class charT, class traits, class Allocator>
        basic_string<charT,traits,Allocator>
            operator+(const basic_string<charT,traits,Allocator>& lhs,
                    const basic_string<charT,traits,Allocator>& rhs);
    template<class charT, class traits, class Allocator>
        basic_string<charT,traits,Allocator>
            operator+(basic_string<charT,traits,Allocator>&& lhs,
                    const basic_string<charT,traits,Allocator>& rhs);
    template<class charT, class traits, class Allocator>
        basic_string<charT,traits,Allocator>
            operator+(const basic_string<charT,traits,Allocator>& lhs,
                    basic_string<charT,traits,Allocator>&& rhs);
    template<class charT, class traits, class Allocator>
        basic_string<charT,traits,Allocator>
            operator+(basic_string<charT,traits,Allocator>&& lhs,
                    basic_string<charT,traits,Allocator>&& rhs);
    template<class charT, class traits, class Allocator>
        basic_string<charT,traits,Allocator>
            operator+(const charT* lhs,
                    const basic_string<charT,traits,Allocator>& rhs);
    template<class charT, class traits, class Allocator>
        basic_string<charT,traits,Allocator>
            operator+(const charT* lhs,
                    basic_string<charT,traits,Allocator>&& rhs);
    template<class charT, class traits, class Allocator>
        basic_string<charT,traits,Allocator>
            operator+(charT lhs, const basic_string<charT,traits,Allocator>& rhs);
    template<class charT, class traits, class Allocator>
        basic_string<charT,traits,Allocator>
            operator+(charT lhs, basic_string<charT,traits,Allocator>&& rhs);
    template<class charT, class traits, class Allocator>
        basic_string<charT,traits,Allocator>
            operator+(const basic_string<charT,traits,Allocator>& lhs,
                    const charT* rhs);
    template<class charT, class traits, class Allocator>
        basic_string<charT,traits,Allocator>
            operator+(basic_string<charT,traits,Allocator>&& lhs,
                    const charT* rhs);
    template<class charT, class traits, class Allocator>
        basic_string<charT,traits,Allocator>
            operator+(const basic_string<charT,traits,Allocator>& lhs, charT rhs);
    template<class charT, class traits, class Allocator>
        basic_string<charT,traits,Allocator>
            operator+(basic_string<charT,traits,Allocator>&& lhs, charT rhs);
 
    template<class charT, class traits, class Allocator>
        bool operator==(const basic_string<charT,traits,Allocator>& lhs,
            const basic_string<charT,traits,Allocator>& rhs);
    template<class charT, class traits, class Allocator>
        bool operator==(const charT* lhs,
                        const basic_string<charT,traits,Allocator>& rhs);
    template<class charT, class traits, class Allocator>
        bool operator==(const basic_string<charT,traits,Allocator>& lhs
                        const charT* rhs);
    template<class charT, class traits, class Allocator>
        bool operator!=(const basic_string<charT,traits,Allocator>& lhs,
                        const basic_string<charT,traits,Allocator>& rhs);
    template<class charT, class traits, class Allocator>
        bool operator!=(const charT* lhs,
                        const basic_string<charT,traits,Allocator>& rhs);
    template<class charT, class traits, class Allocator>
        bool operator!=(const basic_string<charT,traits,Allocator>& lhs,
                        const charT* rhs);
 
    template<class charT, class traits, class Allocator>
        bool operator< (const basic_string<charT,traits,Allocator>& lhs,
                        const basic_string<charT,traits,Allocator>& rhs);
    template<class charT, class traits, class Allocator>
        bool operator< (const basic_string<charT,traits,Allocator>& lhs,
                        const charT* rhs);
    template<class charT, class traits, class Allocator>
        bool operator< (const charT* lhs,
            const basic_string<charT,traits,Allocator>& rhs);
 
    template<class charT, class traits, class Allocator>
        bool operator> (const basic_string<charT,traits,Allocator>& lhs,
                        const basic_string<charT,traits,Allocator>& rhs);
    template<class charT, class traits, class Allocator>
        bool operator> (const basic_string<charT,traits,Allocator>& lhs,
                        const charT* rhs);
    template<class charT, class traits, class Allocator>
        bool operator> (const charT* lhs,
                        const basic_string<charT,traits,Allocator>& rhs);
 
    template<class charT, class traits, class Allocator>
        bool operator<=(const basic_string<charT,traits,Allocator>& lhs,
                        const basic_string<charT,traits,Allocator>& rhs);
    template<class charT, class traits, class Allocator>
        bool operator<=(const basic_string<charT,traits,Allocator>& lhs,
                        const charT* rhs);
    template<class charT, class traits, class Allocator>
        bool operator<=(const charT* lhs,
                        const basic_string<charT,traits,Allocator>& rhs);
    template<class charT, class traits, class Allocator>
        bool operator>=(const basic_string<charT,traits,Allocator>& lhs,
                        const basic_string<charT,traits,Allocator>& rhs);
    template<class charT, class traits, class Allocator>
        bool operator>=(const basic_string<charT,traits,Allocator>& lhs,
                        const charT* rhs);
    template<class charT, class traits, class Allocator>
        bool operator>=(const charT* lhs,
                        const basic_string<charT,traits,Allocator>& rhs);
 
    // swap:
    template<class charT, class traits, class Allocator>
        void swap(basic_string<charT,traits,Allocator>& lhs,
                basic_string<charT,traits,Allocator>& rhs);
 
    // inserters and extractors:
    template<class charT, class traits, class Allocator>
        basic_istream<charT,traits>&
            operator>>(basic_istream<charT,traits>&& is,
                    basic_string<charT,traits,Allocator>& str);
    template<class charT, class traits, class Allocator>
        basic_ostream<charT, traits>&
            operator<<(basic_ostream<charT, traits>&& os,
                    const basic_string<charT,traits,Allocator>& str);
    template<class charT, class traits, class Allocator>
        basic_istream<charT,traits>&
            getline(basic_istream<charT,traits>& is,
                    basic_string<charT,traits,Allocator>& str,
                    charT delim);
    template<class charT, class traits, class Allocator>
        basic_istream<charT,traits>&
            getline(basic_istream<charT,traits>&& is,
                    basic_string<charT,traits,Allocator>& str,
                    charT delim);
    template<class charT, class traits, class Allocator>
        basic_istream<charT,traits>&
            getline(basic_istream<charT,traits>& is,
                    basic_string<charT,traits,Allocator>& str);
    template<class charT, class traits, class Allocator>
        basic_istream<charT,traits>&
            getline(basic_istream<charT,traits>&& is,
                    basic_string<charT,traits,Allocator>& str);
 
    // basic_string typedef names
    typedef basic_string<char> string;
    typedef basic_string<char16_t> u16string;
    typedef basic_string<char32_t> u32string;
    typedef basic_string<wchar_t> wstring;
 
    // numeric conversions:
    int stoi(const string& str, size_t *idx = 0, int base = 10);
    long stol(const string& str, size_t *idx = 0, int base = 10);
    unsigned long stoul(const string& str, size_t *idx = 0, int base = 10);
    long long stoll(const string& str, size_t *idx = 0, int base = 10);
    unsigned long long stoull(const string& str, size_t *idx = 0, int base = 10);
    float stof(const string& str, size_t *idx = 0);
    double stod(const string& str, size_t *idx = 0);
    long double stold(const string& str, size_t *idx = 0);
    string to_string(int val);
    string to_string(unsigned val);
    string to_string(long val);
    string to_string(unsigned long val);
    string to_string(long long val);
    string to_string(unsigned long long val);
    string to_string(float val);
    string to_string(double val);
    string to_string(long double val);
 
    int stoi(const wstring& str, size_t *idx = 0, int base = 10);
    long stol(const wstring& str, size_t *idx = 0, int base = 10);
    unsigned long stoul(const wstring& str, size_t *idx = 0, int base = 10);
    long long stoll(const wstring& str, size_t *idx = 0, int base = 10);
    unsigned long long stoull(const wstring& str, size_t *idx = 0, int base = 10);
    float stof(const wstring& str, size_t *idx = 0);
    double stod(const wstring& str, size_t *idx = 0);
    long double stold(const wstring& str, size_t *idx = 0);
    wstring to_wstring(int val);
    wstring to_wstring(unsigned val);
    wstring to_wstring(long val);
    wstring to_wstring(unsigned long val);
    wstring to_wstring(long long val);
    wstring to_wstring(unsigned long long val);
    wstring to_wstring(float val);
    wstring to_wstring(double val);
    wstring to_wstring(long double val);
 
    // hash support:
    template <class T> struct hash;
    template <> struct hash<string>;
    template <> struct hash<u16string>;
    template <> struct hash<u32string>;
    template <> struct hash<wstring>;
 
    inline namespace literals {
    inline namespace string_literals {
 
    string operator "" s(const char* str, size_t len);
    u16string operator "" s(const char16_t* str, size_t len);
    u32string operator "" s(const char32_t* str, size_t len);
    wstring operator "" s(const wchar_t* str, size_t len);
 
   } // inline namespace string_literals
   } // inline namespace literals
} // namespace std
