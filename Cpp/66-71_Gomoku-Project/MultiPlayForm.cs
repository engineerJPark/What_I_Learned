private const int rectSize = 33; // 오목판의 셀 크기
private const int edgeCount = 15; // 오목판의 선 개수

private enum Horse { none = 0, BLACK, WHITE};
private Horse[,] board = new Horse[edgeCount, edgeCount];
private Horse nowPlayer = Horse.BLACK;

// 게임 진행 여부
private bool playing = false;


public partial class MultiPlayForm : Form{
	private const int rectSize = 33; // 오목판의 셀 크기
	private const int edgeCount = 15; // 오목판의 선 개수

	private enum Horse { none = 0, BLACK, WHITE};
	private Horse[,] board = new Horse[edgeCount, edgeCount];
	private Horse nowPlayer = Horse.BLACK;

	// 게임 진행 여부
	private bool playing = false;
	
	private bool judge(){
		for (int i = 0; i < edgeCount - 4; i++) // 가로
			for (int j = 0; j < edgeCount; j++)
				if (board[i, j] == nowPlayer && board[i + 1, j] == nowPlayer && board[i + 2, j] == nowPlayer &&
					board[i + 3, j] == nowPlayer && board[i + 4, j] == nowPlayer)
						return true;

		for (int i = 0; i < edgeCount; i++) // 세로
			for (int j = 4; j < edgeCount; j++)
				if (board[i, j] == nowPlayer && board[i, j - 1] == nowPlayer && board[i, j - 2] == nowPlayer &&
					board[i, j - 3] == nowPlayer && board[i, j - 4] == nowPlayer)
						return true;

		for (int i = 0; i < edgeCount - 4; i++) // Y = X 직선
			for (int j = 0; j < edgeCount - 4; j++)
				if (board[i, j] == nowPlayer && board[i + 1, j + 1] == nowPlayer && board[i + 2, j + 2] == nowPlayer &&
					board[i + 3, j + 3] == nowPlayer && board[i + 4, j + 4] == nowPlayer)
						return true;

		for (int i = 4; i < edgeCount; i++) // Y = -X 직선
			for (int j = 0; j < edgeCount - 4; j++)
				if (board[i, j] == nowPlayer && board[i - 1, j + 1] == nowPlayer && board[i - 2, j + 2] == nowPlayer &&
					board[i - 3, j + 3] == nowPlayer && board[i - 4, j + 4] == nowPlayer)
						return true;

		return false;
	}
	
	private void refresh(){
		this.boardPicture.Refresh();
		// 모든 돌 지우기
		for (int i = 0; i < edgeCount; i++)
			for (int j = 0; j < edgeCount; j++) board[i, j] = Horse.none;
	}
	
	private void boardPicture_MouseDown(object sender, MouseEventArgs e){
		if(!playing){
			MessageBox.Show("게임을 실행해주세요.");
			return;
		}
		Graphics g = this.boardPicture.CreateGraphics();
		int x = e.X / rectSize;
		int y = e.Y / rectSize;
		if (x < 0 || y < 0 || x >= edgeCount || y >= edgeCount){
			MessageBox.Show("테두리를 벗어날 수 없습니다.");
			return;
		}
		// 이미 놓인 돌이 없어야 새로운 돌을 놓을 수 있다.
		if(board[x, y] != Horse.none) return;
		board[x, y] = nowPlayer;

		if(nowPlayer == Horse.BLACK){
			SolidBrush brush = new SolidBrush(Color.Black);
			g.FillEllipse(brush, x * rectSize, y * rectSize, rectSize, rectSize);
		}
		else{
			SolidBrush brush = new SolidBrush(Color.White);
			g.FillEllipse(brush, x * rectSize, y * rectSize, rectSize, rectSize);
		}

		// 승리여부 판정
		if(judge()){
			status.Text = nowPlayer.ToString() + "플레이어가 승리했습니다.";
			playing = false;
			playButton.Text = "게임시작";
		}
		else{
			nowPlayer = ((nowPlayer == Horse.BLACK) ? Horse.WHITE : Horse.BLACK);
			status.Text = nowPlayer.ToString() + "플레이어의 차례입니다.";
		}
	}
	private void boardPicture_Paint(object sender, PaintEventArgs e){
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
	
	public MultiPlayForm(){ // 다른 부분
		InitializeComponent();
		this.playButton.Enable = false;
	}
	
	private void enterButton_Click(object sender, EventArgs e){
		this.enterButton.Enabled = false;
		this.playButton.Enabled = true;
		this.status.Text = "[" + this.roomTextBox.Text + "]번 방에 접속.";
	}
	
	private void playButton_Click(object sender, EventArgs e){
		if(!playing)
		{
			refresh();
			playing = true;
			playButton.Text = "재시작";
			status.Text = nowPlayer.ToString() + " 플레이어의 차례입니다.";
		}
		else
		{
			refresh();
			status.Text = "게임이 재시작되었습니다.";
		}
	}

}