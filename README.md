# 유사도 검사 프로그램

생성 일시: 2023년 5월 19일 오후 8:26
생성자: 강민정
최종 편집 일시: 2023년 5월 20일 오후 6:23
최종 편집자: 강민정
태그: @프로젝트, 엔지니어링

강민정(2022116624), 박석현(2020110973), 위혜정(2022116007)

---

[Team10 project proposal (1).pdf](%E1%84%8B%E1%85%B2%E1%84%89%E1%85%A1%E1%84%83%E1%85%A9%20%E1%84%80%E1%85%A5%E1%86%B7%E1%84%89%E1%85%A1%20%E1%84%91%E1%85%B3%E1%84%85%E1%85%A9%E1%84%80%E1%85%B3%E1%84%85%E1%85%A2%E1%86%B7%20a41a674091ea429e83dd716858bf944b/Team10_project_proposal_(1).pdf)

- Out GitHub🐈‍⬛

[GitHub - 03Kmj/SystemProgramming_term_prj](https://github.com/03Kmj/SystemProgramming_term_prj/tree/main)

- Topic
    - 파일 간 유사도 검사 프로그램
- 알고리즘?
    - 첫 번째 입력 받는 파일 : 비교대상
    - 2,3~번째 입력받는 파일: 1번 파일과 유사도 비교
    - 1번 파일 입력 후 저장, 2번 파일 먼저 1번과 비교 후 유사도 출력, 3번 파일 1번과 비교 후 유사도 출력…
    - 프로그램 flow: 프로그램 실행 → 시작문구 → 비교 파일 입력 → 진행률 보여줌 → 유사도 결과 출력 → 프로그램 종료
- 프로그램 구성
    - 시작 문구
    - error
        - 존재하지 않는 파일 : “No such file or directory”
        - 파일이 하나도 입력 안됐을 시 & 파일이 하나만 입력됐을 시 : 입력 방법(형식) 알려주기
        - 확장자 범위 넘어갈 시 : 입력 가능한 확장자 알려주기
    - 파일 입력 받기
        - (ex) gcc -o prj prj.c
        - ./ prj  [cmpfile1] [cmpfile2]…
        - 처음에 받는 파일이 main compare
    - 분석
        - 검사대상
            - programming code 검사
            - 범위: c(필요성: 프로그램 코드인지 확인하기 위함 → 확장방안: 세상에 존재하는 모든 프로그램 확장자 집어넣기)
        - [https://liveyourit.tistory.com/57](https://liveyourit.tistory.com/57) 이건 파이썬용(참고)
        - 유사도 검사
            
            ![Untitled](%E1%84%8B%E1%85%B2%E1%84%89%E1%85%A1%E1%84%83%E1%85%A9%20%E1%84%80%E1%85%A5%E1%86%B7%E1%84%89%E1%85%A1%20%E1%84%91%E1%85%B3%E1%84%85%E1%85%A9%E1%84%80%E1%85%B3%E1%84%85%E1%85%A2%E1%86%B7%20a41a674091ea429e83dd716858bf944b/Untitled.png)
            
            - [https://jino-dev-diary.tistory.com/entry/Algorithm-문장의-유사도-분석-편집-거리-알고리즘-Levenshtein-Distance](https://jino-dev-diary.tistory.com/entry/Algorithm-%EB%AC%B8%EC%9E%A5%EC%9D%98-%EC%9C%A0%EC%82%AC%EB%8F%84-%EB%B6%84%EC%84%9D-%ED%8E%B8%EC%A7%91-%EA%B1%B0%EB%A6%AC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Levenshtein-Distance)
            - [https://romg2.github.io/mlguide/01_머신러닝-완벽가이드-08.-텍스트분석-문서-유사도/](https://romg2.github.io/mlguide/01_%EB%A8%B8%EC%8B%A0%EB%9F%AC%EB%8B%9D-%EC%99%84%EB%B2%BD%EA%B0%80%EC%9D%B4%EB%93%9C-08.-%ED%85%8D%EC%8A%A4%ED%8A%B8%EB%B6%84%EC%84%9D-%EB%AC%B8%EC%84%9C-%EC%9C%A0%EC%82%AC%EB%8F%84/)
            - [http://bigdata.dongguk.ac.kr/lectures/TextMining/_book/텍스트-전처리.html](http://bigdata.dongguk.ac.kr/lectures/TextMining/_book/%ED%85%8D%EC%8A%A4%ED%8A%B8-%EC%A0%84%EC%B2%98%EB%A6%AC.html)
            - ✔️ [https://velog.io/@haremeat/python-Text-유사도를-측정하는-여러-방법](https://velog.io/@haremeat/python-Text-%EC%9C%A0%EC%82%AC%EB%8F%84%EB%A5%BC-%EC%B8%A1%EC%A0%95%ED%95%98%EB%8A%94-%EC%97%AC%EB%9F%AC-%EB%B0%A9%EB%B2%95)
            - 문장 하나씩 비교 : **SequenceMatcher 이용**
            - 엔터는 무시하고 다음 문장으로
    - 진행률 progress bar
        - [https://geundung.dev/43](https://geundung.dev/43)
        - 터미널에서 install 시 %나오는 것처럼
        - 시그널 핸들링 : /^c 누르면 종료하시겠습니까(Y/N) → Y종료, N그냥 계속 진행
        - C파일 실행 시 마지막 단계쯤에서 파이썬 파일 실행
