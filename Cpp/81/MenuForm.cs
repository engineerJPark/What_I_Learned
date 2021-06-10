
private void singlePlayButton_Click(object sender, EventArgs e){
	Hide();
	SinglePlayForm singlePlayForm = new SinglePlayForm();
	// childForm_Closed의 결과를 EventHandler에 넣어줘서 다시 메뉴화면으로 돌아올 수 있다.
	singlePlayForm.FormClosed += new FormClosedEventHandler(childForm_Closed);
	singlePlayForm.show();
}

private void multiPlayButton_Click(object sender, EventArgs e)
{
	Hide();
	MultiPlayForm multiPlayForm = new MultiPlayForm();
	multiPlayForm.FormClosed += new FormClosedEventHandler(childForm_Closed);
	multiPlayForm.Show();
}

private void multiPlayButton_Click(object sender, EventArgs e)
{
	Hide();
	AIPlayForm aiPlayForm = new AIPlayForm();
	AIPlayForm.FormClosed += new FormClosedEventHandler(childForm_Closed);
	AIPlayForm.Show();
}

private void exitButton_Click(object sender, EventArgs e){
	System.Window.Forms.Application.Exit();
}

void childForm_Closed(object sender, FormClosedEventArgs e){
	Show();
}

// 레퍼런스 다 찾아보기