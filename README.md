# Similarity Check Program

<img width="661" alt="Untitled" src="https://github.com/03Kmj/SystemProgramming_term_prj/assets/106760660/4a1f2fc0-5633-4f91-ab0c-a7343d61217c">

## 배포 주소

> Github : [https://github.com/03Kmj/SystemProgramming_term_prj](https://github.com/03Kmj/SystemProgramming_term_prj)
> 

> YouTube : https://www.youtube.com/watch?v=tgy5pGEVUsk
>


## 팀 소개

> SystemProgramming 003분반
> 

> 경북대학교 컴퓨터학부 강민정(2022116624), 박석현(2020110973), 위혜정(2022116007)
> 

> 개발기간 2023. 05. 01 ~ 2023. 05. 31
> 


## 프로젝트 소개

### 개요

‘Similarity Check Program’은 C 파일 간의 유사도를 검사하는 command-line program입니다. main file과 sub file을 비교하여 각 비교에 대한 유사도를 생성합니다. 각 파일에 대한 유사도 검사 진행 상황을 나타내기 위해 progress bar를 사용하며, 결과는 텍스트 파일에 저장합니다.


## 시작 가이드

### 사전 요구사항

- c컴파일러 (gcc) 설치
```c
    $ sudo apt-get install gcc
```
- gtk 라이브러리 설치
```c
    $ sudo apt-get install libgtk-3-dev
```
- gio 라이브러리 설치
```c
    $ sudo apt-get install libglib2.0-dev
```
- POSIX 스레드 라이브러리 설치
```c
    $ sudo apt-get install libpthread-stubs0-dev
```
- similarity.c, similarity.py, ls_c.c와 비교할 .c 파일들을 같은 디렉토리 내에 위치시켜야 함.

### 사용법

1. 컴파일 및 링크
    
    1-1 makefile을 활용한 컴파일 및 링크
    ```c
    $  make
    ```
    이미 실행파일이 있을 경우 
    ```c
    $ make clean
    ```
    
    1-2 개별 컴파일 및 링크
    ls_c.c 컴파일 
    
    ```c
    $ gcc ls_c.c -o ls_c
    ```
    
    pthread 라이브러리 링크
    
    ```c
    $ gcc -o progress_bar progress_bar.c -lpthread
    ```
    
    similarity.c 컴파일
    
    ```c
    $ gcc similarity.c sic -o similarity pkg-config —cflags —libs gtk+-3.0
    ```
    
    (similarty.py는 위의 파일들과 같은 디렉토리 내에 위치해야하며, 컴파일 할 필요는 없음.)
    
2. 코드 실행

```c
./similarity
```

3. 파일 추가
실행 후 팝업되는 UI 중 “Drop C File here!”에 비교할 main file과 sub file들을 drag&drop 합니다.
4. 비교 실행
    
    UI 중 “Start Similarity Check!” 버튼을 클릭하여 유사도 검사를 시작합니다.
    
5. 검사 결과 확인
검사 후 터미널창을 통해 검사 결과를 확인할 수 있습니다. 


## 주요 기능

- 유사도 검사가 가능한 파일의 목록을 보여줍니다.(검사 가능 조건: 확장자명이 .c 여야하며, 실행할 파일과 같은 디렉토리 내에 위치해야함.)
- 비교할 파일을 UI에 drag and drop하며, 버튼을 통해 비교를 조작할 수 있습니다.
- 각 유사도 검사 진행에 대해 progress bar를 표시합니다.
- 유사도를 생성하고 결과를 결과 파일에 저장합니다.
- result box와 색상을 사용하여 유사도 결과를 출력합니다.


## Stacks

### Environment
<div align="left">
    <img src="https://img.shields.io/badge/linux-FCC624?style=for-the-badge&logo=linux&logoColor=black"> 
    <img src="https://img.shields.io/badge/Ubuntu-E95420?style=flat-square&logo=Ubuntu&logoColor=white">
    <img src="https://img.shields.io/badge/github-181717?style=for-the-badge&logo=github&logoColor=white">
</div>

### Development
<div align="left">
    <img src="https://img.shields.io/badge/C-A8B9CC?style=flat-square&logo=C&logoColor=white">
    <img src="https://img.shields.io/badge/Python-3776AB?style=flat-square&logo=Python&logoColor=white">
</div>

### Communication
<img src="https://img.shields.io/badge/Notion-000000?style=flat-square&logo=notion&logoColor=white"/></a>
                                                                              
