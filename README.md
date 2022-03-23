# Libft : c library implementation

## Description

---

Author : 
[minkyeki@student.42seoul.kr](mailto:minkyeki@student.42seoul.kr)

Date : 
22/03/08 ~ 22/03/15

Goal : 
`libc` 함수들을 직접 구현, 이를 Static Library로 만들어 추후 프로젝트들에 활용한다.

## Used Testers

---

[https://github.com/Tripouille/libftTester](https://github.com/Tripouille/libftTester)

[https://github.com/jtoty/Libftest](https://github.com/jtoty/Libftest)

[https://github.com/y3ll0w42/libft-war-machine](https://github.com/y3ll0w42/libft-war-machine)

[https://github.com/alelievr/libft-unit-test](https://github.com/alelievr/libft-unit-test)

# 구현할 때 궁금했던 것들

---

## 1. 왜 함수에서 문자를 int 로 받을까?

C 언어 표준 함수를 구현 하면서 몇가지 의문이 들었습니다.  아래의 함수 원형들을 봐볼까요?

```c
/* 문자 c가 아스키 알파벳인지 확인하는 함수 */
extern int ft_isalpha(int c); 

/* 문자 c를 문자열 s 앞에서부터 찾아서 그 주소를 반환하는 함수 */
extern char		*ft_strchr(const char *s, int c);

```

위 두 함수는 모두 인자로 `int c`를 받고 있습니다.  왜 문자를 입력받는 함수에서  `unsigned char`가 아닌 `int` 형을 받는 걸까요?  그 이유는 C언어의 역사에서 찾아볼 수 있습니다. C언어에는 **함수 프로토타입**이 없던 시절이 있었습니다.  지금의 C언어에서 사용하는 함수 원형은 C99에 도입되었죠. 그래서  C99 이전의 코드들(90년대 이전...?) 의 함수 정의는 아래와 같은 모습입니다.

```c
/* K&R definition of a function 
여기서 K는 브라이언 커니핸, R은 데니스 리치입니다. */

int foo(a)  // 함수명 옆에 자료형이 없다.
		int a;  // 중괄호 전에 인자를 명시한다.
{
    // ...
    return 0;
}
```

또 애플 소스코드 사이트를 구경하다보면 앞서 소개드린  K&R 스타일의 함수를 찾아볼 수 있습니다.  예를 들어, 아래 예시는 `memmove()` 함수에 대한 애플 오픈소스 코드입니다.  

```c
void
bcopy(src0, dst0, length)
	void *dst0;
	const void *src0;
	register size_t length;
{
	register char *dst = dst0;
	register const char *src = src0;
	register size_t t;

	// ...
}
```

신기하게도 함수를 정의할 때 인자에 자료형을 적지 않고 다음 줄에서 자료형을 명시해주고 있습니다.  이러한 방식을 `K&R function definition` 이라고 합니다.  이 방식에선 프로그래머가 명시하지 않은 자료형은 모두 `int` 가 됩니다.  (이는 반환 타입도 마찬가지이며, 이러한 규칙을  `"implicit int" rule` 이라고 부르는 것 같네요)  → `“자료형이 없다면, 모두 int다!"`

```c
main(a,b,c,d){        // 함수 반환 타입, 인자 타입이 없으면, 모두 int로 적용된다.
    printf("%d", d);
}
```

K&R 스타일의 상단 코드는, 기능적으로 아래의 코드와 동일합니다.

```c
int main(int a, int b, int c, int d) {
    printf("%d", d);
}
```

왜 `int`가 기본 자료형 일까요?  제가 생각해볼 땐, C언어가 기본 정수형 산술 연산을 `int`단위로 처리하기 때문인 것 같습니다.  C99 이전에 구현된  함수들은  이미 많은 프로그래머들이 사용되어져 왔습니다. 따라서 문자를 인자로 받는 옛 표준함수들을 `int`가 아닌 `unsigned char`로 바꾼다면, 이미 작성된 옛 코드와 호환성을 포기해야 합니다. 이 때문에 현재까지 문자를 `int`형으로 받는 게 아닐까 싶네요.

```c
/* K&R style */
isalpha(c)
		char c;
{
  // ...
}

/* C99 style */
int isalpha(int c)
{
  // ...
} 

/*   ???    */
int isalpha(unsigned char c)
{
  // 표준 함수가 이렇게 바뀐다면...? 어떤 일이 일어날까...? 
}
```

- 참고 자료
    
    ---
    
    [K&R 문법에 대한 블로그 설명](https://jameshfisher.com/2016/11/27/c-k-and-r/)
    
    [스택 오버플로우 : “왜 memset이 char가 아닌 int를 받나요?”](https://stackoverflow.com/questions/5919735/why-does-memset-take-an-int-instead-of-a-char)
    
    [스택 오버플로우 : K&R 함수 선언](https://stackoverflow.com/questions/18421735/c-functions-declaration-in-kr)
    
    [C언어 최적화시 산술 연산에는 int를 사용하라는 글](https://widevery.tistory.com/4)
    
    [C언어 기본 산술연산 자료형에 대한 블로그 설명](https://widevery.tistory.com/4)
    

## 2. 왜 `memset` 은 데이터를 unsigned char로 캐스팅후 대입할까?

---

- *추가 예정입니다.*

## 3. `memcpy`와 `memmove`는 다른 점이 뭘까?

---

- *추가 예정입니다.*

## 4. 표준 함수가 null check (널가드) 를 하지 않는 이유 (⇒ `undefind behavior`)

---

- *추가 예정입니다.*