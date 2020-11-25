
#include <bitset>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/**
 *  块岿粇癟
 *
 *  @param const std::string& cmd   祘Α磅︽嘿
 *  @return none.
 *  @since  0.1.0
 **/
void error(const std::string& cmd, const std::string& msg) {
    std::cout << "Error: " << msg << std::endl;
    std::cout << " type '" << cmd << " -?' to see usage." << std::endl;

    exit(-1);
} // error()

/**
 *  秈锣传矗ボ﹃篶块Α:
 *    Decimal number #dec in #base: #num
 *  矗ボ﹃ㄤい:
 *      #dec  秈计﹃
 *      #base 琌锣传膀┏ (base)秈秈单
 *      #num  琌锣传计﹃
 *  @param const std::string& dec   秈计﹃
 *  @param const std::string& base  计膀┏﹃
 *  @param const std::string& num   锣传计﹃
 *  @return None.
 *  @since  0.1.0
 **/
void numInBase(
    const std::string& dec,
    const std::string& base,
    const std::string& num
) {
    std::cout
        << "Decimal number "
        << dec
        << base
        << num
        << std::endl;
} // numInBase

/**
 *  盢秈计﹃锣传秈计﹃
 *
 *  @param const std::string& dec   秈计﹃
 *  @return std::string             秈计﹃
 *  @since  0.1.0
 **/
std::string dec2bin(const std::string& dec) {
    std::stringstream bin;

    bin << std::bitset<16>(std::stoi(dec));

    numInBase(dec, " in 16 bits binary: ", bin.str());

    return bin.str();
} // decToBin()

/**
 *  盢秈计﹃锣传せ秈计﹃
 *
 *  @param const std::string& dec   秈计﹃
 *  @return std::string             せ秈计﹃
 *  @since  0.1.0
 **/
std::string dec2hex(const std::string& dec) {
    std::stringstream hex;

    hex << "0x" << std::hex << std::stoi(dec);

    numInBase(dec, " in hexadecimal: ", hex.str());

    return hex.str();
} // decToHex()

/**
 *  盢秈计﹃锣传秈计﹃
 *
 *  @param const std::string& dec   秈计﹃
 *  @return std::string             秈计﹃
 *  @since  0.1.0
 **/
std::string dec2oct(const std::string& dec) {
    std::stringstream oct;

    oct << "0" << std::oct << std::stoi(dec);

    numInBase(dec, " in octal: ", oct.str());

    return oct.str();
} // decToOct()

/**
 *  锣传秈矗ボ﹃篶块Α:
 *    #base number #num in decimal: #dec
 *  矗ボ﹃ㄤい:
 *      #base 琌计膀┏ (base)秈秈单
 *      #num  琌计﹃
 *      #dec  秈计﹃
 *  @param const std::string& base  计膀┏﹃
 *  @param const std::string& num   计﹃
 *  @param const std::string& dec   秈计﹃
 *  @return None.
 *  @since  0.1.0
 **/
void numInDec(
    const std::string& base,
    const std::string& num,
    const std::string& dec
) {
    std::cout
        << base
        << " number "
        << num
        << " in decimal: "
        << dec
        << std::endl;
} // numInDec()

/**
 *  盢秈计﹃锣传秈计﹃
 *
 *  @param const std::string& bin   秈计﹃
 *  @return std::string             秈计﹃
 *  @since  0.1.0
 **/
std::string bin2dec(const std::string& bin) {
    std::stringstream dec;

    dec << std::stol(bin, nullptr, 2);

    numInDec("Binary", bin, dec.str());

    return dec.str();
} // bin2dec()

/**
 *  盢秈计﹃锣传秈计﹃
 *
 *  @param const std::string& oct   秈计﹃
 *  @return std::string             秈计﹃
 *  @since  0.1.0
 **/
std::string oct2dec(const std::string& oct) {
    std::stringstream dec;

    dec << std::stol(oct, nullptr, 8);

    numInDec("Octal", oct, dec.str());

    return dec.str();
} // oct2dec()

/**
 *  盢せ秈计﹃锣传秈计﹃
 *
 *  @param const std::string& hex   せ秈计﹃
 *  @return std::string             秈计﹃
 *  @since  0.1.0
 **/
std::string hex2dec(const std::string& hex) {
    std::stringstream dec;

    dec << std::stol(hex, nullptr, 16);

    numInDec("Hexadecimal", hex, dec.str());

    return dec.str();
} // hex2dec()

/**
 *  浪琩 *str* 琌ぃ琌计﹃ノ C++  stol (string-to-long)
 *  ㄧ计浪琩块﹃琌ぃ琌瞶 *计﹃*
 *
 *  @param const std::string& str   璶浪琩﹃
 *  @return bool    true    猭计﹃
 *                  false   Τ獶计じ﹃
 *  @since  0.1.0
 **/
bool is_number(const std::string& str, int base = 10) {
    size_t sz;

    try {
        std::stol(str, &sz, base);
    }
    catch (const std::invalid_argument& e) {
        ;
    }

    return (sz == str.length());
} // is_number()

/**
 *  秈-秈计が锣传代刚ㄧ计
 *
 *  @param const std::string& dec   秈计﹃
 *  @return none.
 *  @since  0.1.0
 **/
bool test_dec_bin(const std::string& cmd, const std::string& dec) {
    std::string bin;
    std::string num;

    std::cout << "C:\\" << cmd << " -b " << dec << std::endl;
    bin = dec2bin(dec);

    std::cout << "C:\\" << cmd << " -B " << num << std::endl;
    num = bin2dec(bin);

    std::cout << std::endl;

    return (dec == num);
} // test_dec_bin();

/**
 *  秈-せ秈计が锣传代刚ㄧ计
 *
 *  @param const std::string& dec   秈计﹃
 *  @return none.
 *  @since  0.1.0
 **/
bool test_dec_hex(const std::string& cmd, const std::string& dec) {
    std::string hex;
    std::string num;

    std::cout << "C:\\" << cmd << " -h " << dec << std::endl;
    hex = dec2hex(dec);

    std::cout << "C:\\" << cmd << " -H " << num << std::endl;
    num = hex2dec(hex);

    std::cout << std::endl;

    return (dec == num);
} // test_dec_hex();

/**
 *  秈-秈计が锣传代刚ㄧ计
 *
 *  @param const std::string& dec   秈计﹃
 *  @return none.
 *  @since  0.1.0
 **/
bool test_dec_oct(const std::string& cmd, const std::string& dec) {
    std::string oct;
    std::string num;

    std::cout << "C:\\" << cmd << " -o " << dec << std::endl;
    oct = dec2oct(dec);

    std::cout << "C:\\" << cmd << " -O " << num << std::endl;
    num = oct2dec(oct);

    std::cout << std::endl;

    return (dec == num);
} // test_dec_oct();

/**
 *  块祘Αㄏノ絛ㄒ
 *
 *  @param const std::string& cmd   祘Α磅︽嘿
 *  @param const std::string& dec   秈计﹃
 *  @return none.
 *  @since  0.1.0
 **/
void sample_usage(const std::string& cmd, const std::string& dec) {
    std::cout << "Examples: " << std::endl << std::endl;

    test_dec_bin(cmd, dec) ? (void)0 : error(cmd, "Dec-Bin converting error!");
    test_dec_hex(cmd, dec) ? (void)0 : error(cmd, "Dec-Hex converting error!");
    test_dec_oct(cmd, dec) ? (void)0 : error(cmd, "Dec-Oct converting error!");
} // sample_usage()

/**
 *  块祘Αㄏノ弧
 *
 *  @param const std::string& cmd   祘Α磅︽嘿
 *  @return none.
 *  @since  0.1.0
 **/
void usage(const std::string& cmd) {
    std::string num;

    std::cout << cmd << " v0.1.0 " << std::endl;
    std::cout << "usage: " << std::endl;
    std::cout << " -H hexadecimal to decimal." << std::endl;
    std::cout << " -h decimal to hexadecimal." << std::endl;
    std::cout << " -O octal to decimal." << std::endl;
    std::cout << " -o decimal to octal." << std::endl;
    std::cout << " -B binary to decimail." << std::endl;
    std::cout << " -b decimal to binary." << std::endl;
    std::cout << " -? print this usage." << std::endl;
    std::cout << " -x some usage samples." << std::endl;
    std::cout << std::endl;

    sample_usage(cmd, "101");
} // usage()

/**
 *  *渡* ㏑把计盢㏑把计计渡棵辊
 *
 *  @param const int argc           ㏑把计计
 *  @param const char *argv[]       ㏑把计皚
 *  @return int
 *  @since  0.1.0
 **/
void args_dump(int argc, char* argv[]) {
    // ┮Τ *㏑把计*
    std::cout << "command line arguments: argv[i]" << std::endl;

    for (int i = 0; i < argc; i++) {
        std::cout
            << std::setfill(' ') << std::setw(3)
            << i << ": "
            << argv[i] << std::endl;
    }
}

/**
 *  祘Α秈翴
 *
 *  @param const int argc           ㏑把计计
 *  @param const char *argv[]       ㏑把计皚
 *  @return int
 *  @since  0.1.0
 **/
int main(int argc, char* argv[]) {
    string num = argv[2];
    string num = argv[1];


    if (argv == "-?") ;
    usage(argv[0]);
        dec2bin(num);
    }
    else if (argv == "-b") {
        dec2bin(num);
    }
    else if (argv == "-B") {
    dec2bin(num);
    }
    else if (argv=="-h") {
    dec2bin(num);
    }
    else if (argv == "-H")[
        dec2bin(num);
    ]
    else if (argv == "-o")[
        dec2bin(num);
    ]
    else if (argv == "-O")[
        dec2bin(num);
    ]
    else if (argv == "-x")[

    
        dec2bin(num);
    ]

    }









{
    // args_dump(argc, argv); // 狦稱璶浪琩祘Α钡Μ
                              // ㏑把计盢玡
                              // 爹秆奔

    // 叫硂柑祘Α絏
    // ㄏ眔絪亩磅︽郎︽㎝ sample.exe 璓
    //
    // 虏虫弧 *祘Α (sample.exe) ︽* 宽碻砏玥
    //
    //  1. sample -? : ㊣ usage()
    //
    //  1. sample -b dec : ㊣ dec2bin(dec)
    //
    //  1. sample -B bin : ㊣ bin2dec(bin)
    //
    //  1. sample -h dec : ㊣ dec2hex(dec)
    //
    //  1. sample -H hex : ㊣ hex2dec(hex)
    //
    //  1. sample -o dec : ㊣ dec2oct(dec)
    //
    //  1. sample -O oct : ㊣ oct2dec(oct)
    //
    //  1. sample -x dec : ㊣ sample_usage(dec)
    //
    //  磅︽絛ㄒ
    //
    //  1. ㏑磅︽ test.bat
    //
    //     C:\path_to\UI_Practice\9th\midterm> test.bat
    //
    //      sample.exe 磅︽絛ㄒ
    //
    //  1. ┪㏑磅︽
    //
    //     C:\path_to\UI_Practice\9th\midterm> sample -?
    //
    //     ㄓ sample.exe ノ猭︽沽刚
    //
    //  代刚祘Α
    //
    //  1. 安砞祘Α絪亩Θ mywork.exe㏑磅︽
    //
    //     C:\path_to\UI_Practice\9th\midterm> test.bat mywork
    //
    //      mywork.exe 代刚磅︽挡狦
    //
    //  肚祘Α --- 癸祘Α骸種
    //
    //  1. ˙ GitHub 盡柑
    //
    //  1. 絋玂璓篒ゎ叫盢硂郎 (midterm.cpp)
    //     肚计厩策キ
    //
    //  穨矗ボ
    //
    //  1. GitHub セ尿穝
    //
    //  1. 篒ゎ戳玡Ω肚郎计厩策キ
    //
    //  
    //    ち抖
 // main()
