using System;
using System.Text;
using System.Windows.Forms;

using System.Net.Sockets; //Net라이브러리, Security라이브러리에서 보안 통신 지원된다. 
using System.Net.Security;
using System.Security.Cryptography.X509Certificates;

namespace Client
{
	public partial class Form1 : Form
	{
		public string serverIP = "127.0.0.1";
		public int port = 9876;
		public string serverDomain = "localhost"; // 인증서에 기재된 내용
		public Form1()
		{
			InitializeComponent();
		}

		private void button_Click(object sender, EventArgs e)
		{
			// socket 생성
			TcpClient client = new TcpClient(serverIP, port); 
			/*이 함수 붙여줌으로써 보안통신 가능*/
			SslStream sslStream = new SslStream(client.GetStream(), false, validateCertificate, null);
			sslStream.AuthenticateAsClient(serverDomain);
			byte[] buf = Encoding.ASCII.GetBytes("Hello SSL!");
			sslStream.Write(buf, 0, buf.Length);
			/*스트림 비운다*/
			sslStream.Flush();
			buf = new byte[4096];
			/*서버로부터 입력받는다.*/
			int length = sslStream.Read(buf, 0, 4096);
			messageText.Text = Encoding.ASCII.GetString(buf, 0, length);
		}
		
		/*인증서 유효성. 테스트여서 항상 True인 것*/
		private bool validateCertificate(object sender, X509Certificate certificate, X509Chain chain, SslPolicyErrors sslPolicyErrors)
		{
			return true;
		}
	}
}