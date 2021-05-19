private const int rectSize = 33; // 오목판의 셀 크기
private const int edgeCount = 15; // 오목판의 선 개수 15*15 크기이다.

private enum Horse { none = 0, BLACK, WHITE}; // 자료형 선언
private Horse[,] board = new Horse[edgeCount, edgeCount]; // 보드를나타내는 변수
private Horse nowPlayer = Horse.BLACK; // 현재 돌을 놓는 사람


public SinglePlayForm(){
	InitializeComponent();
}

private void boardPicture_MouseDown(object sender, MouseEventArgs e){
	// 그림 그리기 위해서 graphics 객체 생성
	Graphics g = this.boardPicture.CreateGraphics();
	// e.X, e.Y는 마우스 이벤트의 장소. 이걸 셀크기로 나눠줘서 몇 번째 선인지 정한다.
	// 0~14까지인데 이걸 벗어나면 예외처리한다.
	int x = e.X / rectSize;
	int y = e.Y / rectSize;
	if (x < 0 || y < 0 || x >= edgeCount || y >= edgeCount){
		MessageBox.Show("테두리를 벗어날 수 없습니다.");
		return;
	}
	
	// 사용자가 선택한 셀 위치 출력
	MessageBox.Show(x + ", " + y);
	
	// 사용자에 따라 색 맞게 원형을 그린다.
	if(nowPlayer == Horse.BLACK){
		SolidBrush brush = new SolidBrush(Color.Black);
		g.FillEllipse(brush, x * rectSize, y * rectSize, rectSize, rectSize);
	}
	else{
		SolidBrush brush = new SolidBrush(Color.White);
		g.FillEllipse(brush, x * rectSize, y * rectSize, rectSize, rectSize);
	}
}

// 오목판 초기 구성. refresh마다 다시 그려진다.
private void boardPicture_Paint(object sender, PaintEventArgs e)
{
	Graphics gp = e.Graphics;
	Color lineColor = Color.Black; // 오목판의 선 색깔
	Pen p = new Pen(lineColor, 2); // 두번째 인자는 굵기
	
	// 4번 그어서 테두리를 만든다.
	gp.DrawLine(p, rectSize / 2, rectSize / 2, rectSize / 2, rectSize * edgeCount - rectSize / 2); // 좌측
	gp.DrawLine(p, rectSize / 2, rectSize / 2, rectSize * edgeCount - rectSize / 2, rectSize / 2); // 상측
	gp.DrawLine(p, rectSize / 2, rectSize * edgeCount - rectSize / 2, rectSize * edgeCount - rectSize / 2, rectSize * edgeCount - rectSize / 2); // 하측
	gp.DrawLine(p, rectSize * edgeCount - rectSize / 2, rectSize / 2, rectSize * edgeCount - rectSize / 2, rectSize * edgeCount - rectSize / 2); // 우측
	
	// 테두리 내부의 선 그리기
	p = new Pen(lineColor, 1);
	// 대각선 방향으로 이동하면서 십자가 모양의 선 그리기
	for (int i = rectSize + rectSize / 2; i < rectSize * edgeCount - rectSize / 2; i += rectSize)
	{
		gp.DrawLine(p, rectSize / 2, i, rectSize * edgeCount - rectSize / 2, i);
		gp.DrawLine(p, i, rectSize / 2, i, rectSize * edgeCount - rectSize / 2);
	}
}

// C++, C# 레퍼런스와 구글링으로 의미 다 파악해야한다.
// enum 자료형 선언에 관한 https://boycoding.tistory.com/179