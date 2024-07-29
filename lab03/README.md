##  Lab A
1) 달팽이 문제 
- 문제 설명
  - 달팽이 배열 변형 문제
  - 입력 받은 숫자를 n이라고 할 때 n*n 달팽이 배열을
num.out 파일을 만들어 출력해주세요.
  - 1-9까지 9가지 숫자만을 갖고 출력 해야하며 n의 범위는 1-50입니다.(그 외의 숫자는 예외처리)
  - 입력은 어떤 방식으로 받아도 좋으나, fputc를 사용해서 풀어주세요.
- 힌트 
  - int형에서 char로 변경하는 것을 조심하기.
  - 1부터 9까지 한 자리 수만 가지고 하면 됩니다.
  - 바로 올려도 되지만 배열을 만들어 저장하고 한다면 좀 더 쉽게 되지 않을까요?

<a href="https://imgbb.com/"><img src="https://i.ibb.co/L5SFNzc/A-1-result.png" alt="A-1-result" border="0"></a>


## Lab B
### 1. 바이너리와 텍스트의 속도차이
- 준비물
  - 파일 : 각 파일에는 위에서 정의된 구조체가 동일한 개수로 저장되어 있음
    - test.bin → 구조체들이 바이너리 형식으로 저장된 파일
    - test.txt → 구조체들이 텍스트 형식으로 저장된 파일
- 과정1- 바이너리 파일을 끝까지 읽기
  - 제공되는 바이너리 파일을 끝까지 읽기
  - 힌트 → `fread()`
    - 위에서 정의된 구조체의 크기만큼 읽는 것을 반복하기

- 과정2- 텍스트 파일을 끝까지 읽기
  - 제공되는 텍스트파일을 끝까지 읽기
  - 힌트 → `fscanf()`
    - 위에서 정의된 구조체의 멤버변수 순서대로 읽는 것을 반복하기

<a href="https://ibb.co/Qv2wg09"><img src="https://i.ibb.co/pjtF7q2/1-result.png" alt="1-result" border="0"></a>

---

### 2. FIFO(First In First Out)
- 준비물
  - 프로세스의 개수는 4개(고정)
  - 총 2줄로 첫번째 줄이 프로세스가 도착한 시간(arrive Time) , 두번째 줄이 처리하는데 걸리는 시간
(burst Time)
  - 도착한 시간을 기준으로 오름차순 정렬( 왼쪽에 있는 프로세스가 제일 먼저 도착한 프로세스)
- 과정1- input.txt를 읽기
  - 결과 화면에 프로세스별로 도착한시간, 처리하는데 걸리는 시간 출력

- 과정2- 현재 처리 중인 프로세스를 문자열로 표현
  - 현재 CPU에 처리 중인 프로세스가 없을 경우 → X로 표현
  - 같은 시간에 들어온 프로세스일 경우 → 알파벳 순으로 처리

<a href="https://imgbb.com/"><img src="https://i.ibb.co/FHsYjr8/2-result.png" alt="2-result" border="0"></a>


---

### 3. Integer Values in 3 Bytes
- 준비물
  - binary 파일
- Input file : 3 byte 정수 숫자 들 (Big-endian)
  - System call을 통해 읽을 것

- Output file : 공백으로 구분된 정수들
  - Standard IO를 통해 출력 할것

<a href="https://ibb.co/Q6tsBLr"><img src="https://i.ibb.co/Hr3mv6n/3-result.png" alt="3-result" border="0"></a>
