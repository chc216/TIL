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
    