Today I Learned

1월 4일
git 사용법 학습
1. git 저장소 만들기
    git init

2. github 리포지토리와 연결하기
    git remote add origin 저장소 주소

3. 커밋하기
    스테이지에 올린 후 커밋 메시지 작성과 함께 커밋
    git add 파일 이름 --> git commit or git commit -m "커밋 메시지"

4. 커밋 이력 조사 및 체크아웃
    git log -> 커밋 이력 출력
    git checkout 커밋아이디 Or 브랜치 --> 해당 위치로 이동(head포인터를 이동한다고 함 맞나?)

    --실수했던 점--
push할 때 push할 저장소와 브랜치를 지정하지 않음 --> git push origin main으로 해결
//여기서 origin이란 ? : 깃허브 저장소를 부르는 애칭으로 생각한다
    --위의 오류를 해결하면서 배운 점--
    //git branch 이름 : 새로운 브랜치 생성
    //main브랜치로 체크아웃한 이후 git merge 브랜치 이름 : 해당 브랜치를 main브랜치로 병합한다 --> 아마도 프로젝트할 때 메인 흐름은 main브랜치로 버전관리를 갖고 가고, 새로운 기능을 추가(main과 겹치지 않는 함수같은거)할 때 새로운 브랜치를 통해 개발 및 버전관리를 하다가 끝나면 main과 병합하는 것 같음
   
5. 폴더 변경 후 저장소에 반영하는 방법
    폴더 이름 및 경로 변경 : git mv ~~ ~~
    폴더 관련 변경이 있을 땐 : git status로 untracked파일 확인 후 add및commit-->push
6. vim사용법
    vim ~~ : 해당 ~파일이 존재하면 vim열고, 존재하지 않으면 파일 생성 후 연다
    i : insert모드, 글을 작성할 수 있도록 한다
    esc-->:wq  : 인서트 모드에서 명령모드로 돌아온 뒤 저장 및 실행종료를 한다 


1월 8일

1. pull request?
: 포크한 원본 리포지토리에 푸시하면 푸시한 브랜치를 원본 리포지토리에 병합할지 말지를 결정하는 것(?)

PR및 깃 작동과정이 잘 요약된 링크
*https://velog.io/@zansol/Pull-Request-이해하기

장점 : 풀리퀘스트를 해야하니 자연스럽게 푸시한 사람의 코드 리뷰 가능, 풀리퀘스트를 하면서

2. 포크? 클론?
    포크 : 어떤 리포지토리를 내 깃허브 리포지토리로 복사해오는것(포크로 찍어서 내 리포에 갖고온다고 생각)
    내 리포지토리에서 포크한 원본 리포지토리로 특정 브랜치를 푸시하면 pull request가 들어온다
    클론 : 내 깃허브 리포지토리에서 로컬 리포지토리로 복사해오는 것
    로컬에서 원격으로는 푸시를 한다
    리모트 : 로컬 저장소와 원격 저장소를 연동하는 것, git remote -v로 확인 가능

    

