##  Lab A
1) 시스템 정보 읽어오기
- 문제 설명
  - 시스템에 설치된 운영체제와 호스트명으로 폴더
를 생성 
  - 각각의 폴더 안에 시스템 정보를 담은
파일을 저장
- 조건 
  - 다음 함수들을 이용하여 작성하시오.
    1. 폴더 -> uname()
    1. 운영체제명의 파일 -> sysinfo()
    1. 호스트명의 파일 -> sysconf()

  |sysinfo|sysconf|
  |------|---|
  |전체 Ram memory|한 UID 허용 최대 프로세스 개수|
  |사용 가능한 Ram memory|프로세스당 열 수 있는 최대 파일 개수|
  |사용중인 Ram memory|한 UID 당 열 수 있는 최대 파일 개수|
  |전체 Swap memory||
  |사용 가능한 Swap memory||
  |사용 중인 Swap memory||

    <a href="https://ibb.co/rkY66n3"><img src="https://i.ibb.co/7vPWW7Q/A-1.png" alt="A-1" border="0"></a>
---  
2) Group info 와 User info 비교하기
- 문제 설명
  - User passwd file에 있는 각각의 User info에서 GID를 찾기
  - Group file에 있는 같은 GID를 찾아 이름을 비교
    - file 이름이 다를 경우 파일에 출력


<a href="https://ibb.co/3dBGqz1"><img src="https://i.ibb.co/QQrzRd9/A-2.png" alt="A-2" border="0"></a>



## Lab B
### 1. Shadow 정보 추출 및 해석
- Shadow 파일의 계정정보에 들어있는 encrypted password의 형
  - [$Hashid $Salt $Hash value]
- 과정 1
  -  계정 1개 추가(id, pw 자유) –> sudo adduser sp11
- 과정2
  - /etc/shadow에서 추가한 계정(sp11)의 암호화된
password를 얻어오기
  - 얻어온 정보 Hashid, Saltm Hash value로 나누어 출력
- 과정 3 
  - 계정의 최종변경일에 대한 날짜를 출력

<a href="https://ibb.co/qyKCy37"><img src="https://i.ibb.co/6nz8n7r/B-1.png" alt="B-1" border="0"></a>

---

### 2. 모든 사용자의 소속된 그룹 출력
- 각각의 사용자가 소속된 모든 그룹 출력하기
- 조건 : 강의 내용 이외의 라이브러리 사용금지

<a href="https://imgbb.com/"><img src="https://i.ibb.co/tBf1hMc/B-2.png" alt="B-2" border="0"></a>