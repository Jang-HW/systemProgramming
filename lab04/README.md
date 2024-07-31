##  Lab A
1) 폴더 속 확장자 파일 찾기
- 문제 설명
  - Sample 폴더 속 파일 중 .c 확장자를 찾아서
모두 출력
  - 임의의 텍스트 파일에 .c 파일들의
내용을 모두 출력
- 조건 
  1. 임의의 텍스트 파일은 sample 폴더 속에 만듭니다.
  1. `.c` 파일 속 내용은 모두 영어로 되어 있습니다.
  1. Sample 폴더 속 텍스트 파일을 만드는 것 말고는
파일의 내용을 수정하거나 삭제해서는 안 됩니다.

    <div  href="https://imgbb.com/"><img src="https://i.ibb.co/DtGGSsj/labA-1.png" alt="labA-1" border="0"></div >
    <div  href="https://imgbb.com/"><img src="https://i.ibb.co/C62R2WX/lab-A-1-2.png" alt="lab-A-1-2" border="0"></div >
---  
2) 빈폴더삭제, 빈폴더가아니면경로찾기
- 문제 설명
  - (Ubuntu의 ASCII 코드 합)%12의 cur offset을 가진 폴더로 들어가 폴더를 검색해 비어 있는지 판단
  - 빈 폴더면 삭제, 빈 폴더가 아니면 폴더 속 파일의 경로를 출력
- 힌트
  1. cuff offset = (ASCII 코드 값들의 합 % 12) 폴더로 이동합니다.
  1. 그 폴더 속에 들어가 폴더를 검색합니다.
  1. 폴더만 검색하여 비어 있으면 폴더를 삭제하고 안내 문구 출력합니다. (“OOO 폴더를 삭제 했습니다.”)
  1. 비어 있지 않으면 폴더 속 파일의 경로를 출력합니다.

  미완성 상태로 offset 값이 1, 2, 3, ... 이런 식으로 나오지 않는 문제가 있습니다. 
  <a href="https://imgbb.com/"><img src="https://i.ibb.co/Hx1xCVV/labA-2.png" alt="labA-2" border="0"></a>



## Lab B
### 1. 해당 파일 경로 출력
- 과정1- 디렉토리(4-1) 가져오기
  - 파일이나 디렉토리를 추가 및 삭제 불가

- 과정2- 디렉토리(4-1), 파일 이름 입력 후 경로 출력
  - 상위 디렉토리 순으로 경로 출력
  - 동일한 이름의 파일이 존재할 시 모두 출력
  - 힌트 → 문자열 함수 사용 <string.h>

<a href="https://ibb.co/z77LCcL"><img src="https://i.ibb.co/Jyyb8Lb/labB-1.png" alt="labB-1" border="0"></a>

---

### 2. 파일 분류하기
- 과정1- 디렉토리(4-2) 가져오기
  - 가져와 FIFO 파일, SOFT LINK 파일 생성

- 과정2- 디렉토리(4-2), 특정 권한 입력 후 경로 출력
  - F : FIFO 파일
  - D : 디렉토리
  - R : 일반 파일
  - B : 블록 장치 특수 파일
  - I : 심볼릭 링크 파일

- 동일한 권한을 가진 파일 모두 출력하도록
- 실행 결과에 F, I, R, D 필수 출력 !


<sys/stat.h>랑 매핑이 다른거 같습니다. </br>
<a href="https://imgbb.com/"><img src="https://i.ibb.co/nDmmZHh/lab-B-2-mapping-is-different.png" alt="lab-B-2-mapping-is-different" border="0"></a>