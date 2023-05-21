# 파일 간 유사도 검사 프로그램

생성 일시: May 19, 2023 8:26 PM
생성자: 강민정
최종 편집 일시: May 21, 2023 2:33 PM
최종 편집자: 혜정 위
태그: @프로젝트, 엔지니어링

강민정(2022116624), 박석현(2020110973), 위혜정(2022116007)

---

[Team10 project proposal (1).pdf](%E1%84%91%E1%85%A1%E1%84%8B%E1%85%B5%E1%86%AF%20%E1%84%80%E1%85%A1%E1%86%AB%20%E1%84%8B%E1%85%B2%E1%84%89%E1%85%A1%E1%84%83%E1%85%A9%20%E1%84%80%E1%85%A5%E1%86%B7%E1%84%89%E1%85%A1%20%E1%84%91%E1%85%B3%E1%84%85%E1%85%A9%E1%84%80%E1%85%B3%E1%84%85%E1%85%A2%E1%86%B7%20a41a674091ea429e83dd716858bf944b/Team10_project_proposal_(1).pdf)

- Out GitHub🐈‍⬛

[GitHub - 03Kmj/SystemProgramming_term_prj](https://github.com/03Kmj/SystemProgramming_term_prj/tree/main)

- 알고리즘
    - 첫 번째 입력 받는 파일 : 비교 대상
    - 2,3~번째 입력 받는 파일 : 1번 파일과 유사도 비교
    - 1번 파일 입력 후 저장 → 2번 파일 입력 후 저장, 1번과 2번 비교 후 유사도 출력 → 3번 파일 입력 후 저장, 1번과 3번 비교 후 유사도 출력 → …
    - 프로그램 flow : 프로그램 실행 → 시작문구 → 비교 파일 입력 → 진행률 보여줌 (Ctrl+C → 종료할 건지 질문 → 종료/진행) → 유사도 결과 출력 → 프로그램 종료
- 프로그램 구성
    - 시작 문구
        - /*
            
            *
            *Similarity check
            *Purpose: This program checks the similarity between c codes.
            *Writer: mjkang, shpark, hjwi
            *
            */
            
    - error 핸들링
        - 존재하지 않는 파일 : if(file==NULL) fprintf(stderr, "%s : No such file or directory", argv[index]);
        - 파일이 하나도 입력 안됐을 시 & 파일이 하나만 입력됐을 시 : 입력 방법(형식) 알려주기
    - 파일 입력 받기
        - 시작 문구 이후에 파일 입력하라고 출력 → 파일 입력
        - 유사도 출력 중간 중간에 해주고 결과만 마지막에
    - 분석
        - 검사대상
            - programming code 검사
        - 유사도 검사
            
            ![Untitled](%E1%84%91%E1%85%A1%E1%84%8B%E1%85%B5%E1%86%AF%20%E1%84%80%E1%85%A1%E1%86%AB%20%E1%84%8B%E1%85%B2%E1%84%89%E1%85%A1%E1%84%83%E1%85%A9%20%E1%84%80%E1%85%A5%E1%86%B7%E1%84%89%E1%85%A1%20%E1%84%91%E1%85%B3%E1%84%85%E1%85%A9%E1%84%80%E1%85%B3%E1%84%85%E1%85%A2%E1%86%B7%20a41a674091ea429e83dd716858bf944b/Untitled.png)
            
            - ✔️ [https://velog.io/@haremeat/python-Text-유사도를-측정하는-여러-방법](https://velog.io/@haremeat/python-Text-%EC%9C%A0%EC%82%AC%EB%8F%84%EB%A5%BC-%EC%B8%A1%EC%A0%95%ED%95%98%EB%8A%94-%EC%97%AC%EB%9F%AC-%EB%B0%A9%EB%B2%95)
            - 문장 하나씩 비교 : **SequenceMatcher 이용**
            - 엔터는 무시하고 다음 문장으로
            - pipe 사용하기 : 파이썬 파일 실행 & 값 return 받기
    - 진행률 progress bar
        - [https://geundung.dev/43](https://geundung.dev/43)
        - 터미널에서 install 시 %나오는 것처럼
            
            a와 b 유사도 —%
            
            a와 c 유사도 —%
            
            ⇒ 가장 유사한 파일~~~
            
        - 시그널 핸들링 : /^c 누르면 종료하시겠습니까(Y/N) → Y종료, N그냥 계속 진행
            - y/n 말고 다른 거 들어오면 어쩔갸
        - C파일 실행 시 마지막 단계쯤에서 파이썬 파일 실행
