.Net 설치
C# 사용 : 실제 화면 띄울 것
Windows Form 앱 .Net project : 게임서버와 통신하기 위한 클라이언트 역할 수행한다.

button 2개 넣고 form size 600 400
text : Gomoku game project
button1 text : 혼자하기 size : 100 40 name : singlePlayButton
button2 text : 종료하기 size : 100 40 name : exitButton

엑셀 VBA처럼, 버튼 더블클릭하면 이벤트에 관한 프로그램 나온다.\

Winform으로 SinglePlayForm.cs 만들기

*******************
picturebox : name : boardpicture Backcolor : 255, 255, 216 size : 500, 500 location : 20, 20
Mousedown, paint 이벤트 설정 : 

SiglePlayForm의 경우 size : 880, 500


************
button 생성, playButton명명, size 100, 40 text : 게임시작, 
label 추가 autosize False, size : 272, 15, te3xdtalign : middlecenter name: status


***************
button 생성, playMultiPlay명명, size 100,40 text : 함께하기
Winform으로 MultiPlayForm.cs 만들기
SinglePlayForm과 같은 방식으로 만들어주기
button 생성 : 접속하기. enterButton
button 생성 : 게임시작 playButton
label 생성 : status autosize:false middlealign 방을 입력하여 접속해주세요
