# C-programming
//MyString
구현 기능

* 유의사항

- strcpy, strcat 을 포함한 모든 string.h 또는 cstring 에서 제공하는 문자열 라이브러리 함수 사용 금지

- operator >> 와 operator <<, stoi() 를 제외한 모든 함수는  멤버함수로 구현할 것

- 아래 상세하게 명시하지 않은 모든 기능은 일반 string 클래스와 동일하게 작동하도록 구현할 것

2.1 기본 기능

- default 생성자  MyString::MyString() : 초기 크기 8byte의 문자열 공간을 생성하고 빈 문자열로 초기화 

- [변경]  복사생성자 MyString::MyString(const MyString &srcStr) : srcStr로부터의 깊은 복사로 생성자 구현

- 파괴자 MyString::~MyString() : 반드시 구현할 것. 제대로 구현하지 않으면 큰 감점 부여.

- 대입연산자 MyString::operator = (const MyString &srcStr) : srcStr로부터의 깊은 복사로 대입연산 구현

- 문자열 길이(전체 용량이 아닌 문자열 자체의 길이) return하는 int MyString::length()

- 문자열의 pos 위치에 있는 글자를 return 하는 char MyString::at(int pos)

- 문자열이 비어있으면 true를, 아니면 false를 return하는 bool MyString::empty()

- 입력을 위한 연산자 istream& operator >>(istream& is, MyString &str)의 일반 함수 구현

   : 엔터키까지 입력.  getchar() 사용 가능

- 출력을 위한 연산자 ostream& operator <<(ostream& os, const MyString &str)의 일반 함수 구현


2.2 필수 기능 (난이도 중. 35점)

모든 기능은 기존 string과 동일하게 동작해야 함

- 대입연산자 MyString& MyString::operator = (const char *srcStr) : srcStr로부터의 깊은 복사로 대입연산 구현

- 문자열 연결 연산자 const MyString MyString::operator + (const char *str2nd) 

  문자열 연결 연산자 const MyString MyString::operator + (const MyString& str2nd) 

- [변경] 문자열 연결 함수 const MyString MyString::append(const char *str2nd)

  문자열 연결 함수 const MyString MyString::append(const MyStsring& str2nd)

              : *this에 str2nd를 연결하여 저장

- 문자열 동등성을 비교하여 bool을 return하는 연산자 bool MyString::operator ==(const MyString &str)과, bool MyString::operator !=(const MyString &str)

- 부분문자열을 찾아 위치를 return하는 int MyString::find(const char *subStr)과int MyString::find(const MyString subStr)                    

  pos위치로부터 부분문자열을 찾아 위치를 return하는 int MyString::find(int pos, const char *subStr)과
  int MyString::find(int pos, const MyString subStr): 부분 문자열이 없으면 -1 return


2.3 추가 기능 (난이도 중상. 35점)

(const  등의 명시나 return type은 적절하게 알아서 구현. 적절성은 평가 점수에 고려됨)

(문자열 크기를 resize해야 하는 경우를 꼼꼼하게 잘 살펴서 구현할 것.

  resize는 항상 *2로 구현되도록 할 것)

- 생성자 MyString(const char *) : 전달되는 문자열에 대한 깊은 복사로 복사생성자 구현

- 연결대입연산자 operator += (char *str2nd) : *this에 str2nd 문자열을 연결하여 저장

- 문자열 비교연산자 operator <(MyString), operator <=(MyString), operator >(MyString), operator >=(MyString)

- 문자열 비교연산자 operator <(char *), operator <=(char *), operator >(char *), operator >=(char *)

- 부분문자열 추출 substr(int pos, int cnt) : 문자열 내에서 pos 위치로부터 cnt 개의 글자를 새로운 MyString 객체에 복사하여 return
- 삽입 insert(int pos, char *subStr), insert(int pos, MyString subStr) : pos 위치에 subStr 문자열을 끼워넣기

- 대체 replace(int pos, int cnt, char *subStr), replace(int, int, MyString)
   : pos 위치에서 cnt길이의 부분문자열을 subStr로 대체

- 삭제 erase(int pos, int cnt) : pos 위치에서 cnt 길이의 부분문자열을 삭제

- 일반함수 int stoi(const MyString &str, int pos = 0 , int base = 10) 
: str[pos]로부터의 숫자부분을 정수로 변환하여 return. 
base는 2~16값이 들어올 수 있으며 str[idx]로부터의 숫자부가 2진수~16진수일 수 있음을 의미

- operator [](int pos) : at(pos)와 동일한 기능 수행


