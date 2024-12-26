## SWHomework1
* 요구사항
  
**1. 이미지를 표시할 수 있는 다이얼로그를 생성**

**2. 시작좌표(x1,y1), 종료좌표(x2,y2)를 입력 받을 수 있는 UI를 생성**

![image](https://github.com/user-attachments/assets/b6a21def-6f75-4f7b-ba81-3334ad82bbbe)

상단에는 좌표를 입력받는 에디터박스와 기능을 실행할 버튼 3가지가 존재합니다. 아래에는 이미지를 띄울 다이얼로그를 추가했습니다. 
좌표를 입력받는 (x1, y1)과 (x2, y2)는 800 X 600에서 화면에 원이 나가지 않도록 범위를 설정한 상태입니다. 
![image](https://github.com/user-attachments/assets/06c00a52-54d5-459e-bf74-2daa4cbf542b)

만약 실행하게 되시면, x1과 x2는 50 이상 750 이하로 입력해주셔야 하며, y1과 y2는 50이상 550 이하로 입력해주셔야 합니다.

**4. Draw 버튼 클릭시 (x1, y1) 좌표를 중심으로하는 랜덤한 크기의 원 그림**
![image](https://github.com/user-attachments/assets/43c1cc11-2fb0-4a58-b25f-aa2548b00dd4)

범위를 알맞게 입력하고 Draw버튼을 선택하면 랜덤 반지름의 원이 그려지게 됩니다. 여기서, 원의 반지름은 50이 넘지 않게끔 설정하였습니다.

**5. Action 버튼 클릭시 (x1, y1) 좌표에서 (x2, y2) 좌표로 일정 픽셀 간격으로 원을 이동시키며, 이동할 때마다 실행파일이 위치한 폴더 내의 image 폴더에 bmp 또는 jpg(jpeg) 포맷으로 저장**
![image](https://github.com/user-attachments/assets/85e9db45-7dfa-4693-90bc-f9976a2eb8c3)

Draw 버튼 선택 후 Action 버튼을 선택하면 해당 자리에서 (x2, y2) 좌표 위치로 일정 픽셀 이동하게 됩니다. 일정 픽셀 이동하고 멈추므로, 목표인 (x2, y2)에 도달하려면 여러번 선택해야 합니다.
Action 버튼 선택 한번에 image 폴더의 bmp로 저장이 되며, 반드시 실행 파일 안에 image 폴더를 생성해야 저장됩니다.

**6. Open 버튼 클릭시 탐색기 창을 통해 이미지를 1개를 선택해서 불러오고 다이얼로그에 출력. 이 때 출력된 원의 중심 좌표에 X 모양을 그리고 좌표값을 같이 표시**

![image](https://github.com/user-attachments/assets/9fb8cca9-2780-4310-a412-15c2bc30ea08)
Open 버튼을 선택하면 탐색기 창이 뜨게 됩니다. 

![image](https://github.com/user-attachments/assets/6939cb69-c183-4020-b8c3-a4374107523a)

bmp 파일을 선택하면 요구사항처럼 X모양을 그리게 되고 좌표가 나오게 됩니다.
이미지 파일은 반드시 Action으로 그려진 bmp 이미지 파일을 넣어야하며, 다른 확장자 파일은 예외처리를 하지 않은 상태라 제대로 작동하지 않을 수 있습니다.

* 주 클래스 설명

DialogImg.cpp : 이미지를 표시하고 관리하는 Dialog 클래스

SWHomework1Dlg.cpp : 좌표, 각종 버튼을 관리하고 이벤트를 실행하는 클래스
