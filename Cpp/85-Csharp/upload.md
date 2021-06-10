## 구조체, 클래스

- C# .NET의 기본 데이터 타입은 struct로 정의되어 있습니다.
- int, float, double 등의 데이터 타입은 struct로 정의된 형식입니다.
- C#의 구조체는 클래스와 흡사한 형태를 가지고 있으나 상속은 할 수 없습니다.
- 객체 지향 프로그래밍을 위하여 C#에서도 클래스를 사용해야 합니다.

```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace ConsoleApp1 {
	class Program {
		static void Main(string[] args){
			int a = 5;
			string b = a.ToString(); //struct로 데이터타입이 정의되어있어서, 자료형에 메서드가 있다.
		}
	}
}
```

구조체 예시
사실상 클래스와 흡사한 상태로 이용할 수 있다.
```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace ConsoleApp1 {
	struct Adder {
		public int x, y;
		public Adder(int x, int y) {
			this.x = x;
			this.y = y;
		}
		public string GetResult() {
			return x + " + " + y + " = " + (x + y);
		}
	}
	class Program {
		static void Main(string[] args){
			Adder adder = new Adder(10, 20); // 수거 안해도 garbage collector가 알아서 수거해간다.
			Console.WriteLine(adder.GetResult());
		}
	}
}
```

C# 클래스

- C#의 클래스의 기본적인 특성은 C++의 클래스와 동일합니다.
- 메소드(Method): 특정한 기능을 수행하는 함수를 의미합니다. C#에서는 앞 문자가 대문자로 시작합니다.(메서드 뿐 아니라, 모든 함수)
- 필드(Field): 클래스의 내부 변수를 의미합니다. C++과 마찬가지로 접근제한자를 사용할 수 있습니다. 일반적으로 내부 변수는 객체 지향 프로그래밍의 원리에 따라 private을 이용합니다.
- 필드에 대해 외부에서 접근하려면 public인 메서드를 통해서 접근해야한다.

```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Student{
	private int id;
	private string name;
	private int score;
	public Student(int id, string name, int score){
		this.id = id;
		this.name = name;
		this.score = score;
	} // 여기서는 this가 포인터가 아닌가?
	public void Show(){
		Console.WriteLine("학번 : " + id);
		Console.WriteLine("이름 : " + name);
		Console.WriteLine("점수 : " + score);
	}
}

namespace ConsoleApp2{
	class Program{
		static void Main(string[] args){
			Student student = new Student(2017170000, "공대창고", 100);
			student.Show();
		}
	}
}
```

----

# C# Generics

- C# Generics는 C++의 템플릿과 흡사하게 동작합니다.(<> 형태를 사용한다.)
- C# Generics는 int, float, double 등의 데이터 타입을 필요에 따라서 적용할 수 있습니다.
- C# 클래스, 메소드, 인터페이스 등에 타입 파라미터(<T>)를 붙여 구현할 수 있습니다.


스택을 만드는 예제
```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// 이거 주석처리해도 실행되는데 뭐징??
class Stack<T>{
	T[] stack;
	int top = -1;
	public Stack(){
		stack = new T[100];
	}
	public void Push(T element){
		stack[++top] = element;
	}
	public T Pop(){
		return stack[top--];
	}
}

namespace ConsoleApp2{
	class Program{
		static void Main(string[] args){
			Stack<string> stack = new Stack<string>();
			stack.Push("team1");
			stack.Push("team2");
			stack.Push("team3");
			
			Console.WriteLine(stack.Pop());
			Console.WriteLine(stack.Pop());
			Console.WriteLine(stack.Pop());
		}
	}
}
```
C# Generics collection class에 자체 stack 클래스가 있어서 바로 Stack<string> stack이라고 작성해서 사용할 수 있다.

C# Generics collection class(라이브러리다.)를 이용해보자
List의 경우는 

```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2{
	class Program{
		static void Main(string[] args){
			List<string> list = new List<string>();
			list.Add("team1");
			list.Add("team2");
			list.Add("team3");
			
			for(int i = 0; i < 3; i++){
				Console.WriteLine(list[0]);
				Console.WriteLine(list[1]);
				Console.WriteLine(list[2]);
			}

		}
	}
}
```
컴파일 에러 난다고 표시되면 alt + enter 눌러서 오류 내용 바로 확인하자.

Generics collection class 중 Dictionary는 C++의 map, set과 비슷하다.
그리고 Hash와 같이 동작한다.
```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2{
	class Program{
		static void Main(string[] args){
			// <>안에서 왼쪽은 key, 오른쪽은 value다.
			Dictionary<string, int> dictionary = new Dictionary<string, int>();
			dictionary["team1"] = 98;
			dictionary["team2"] = 83;
			dictionary["team3"] = 78;
			
			// 특정한 key값을 가지고 있는지 확인 한다.
			if(dictionary.ContainsKey("team1")){
				Console.WriteLine("team1 score : " + dictionary["team1"] + "points");
			}
			// KeyValuePair 객체로 딕셔너리에 접근한다.
			// 딕셔너리의 모든 키와 값이 pair에 들어간다.
			foreach(KeyValuePair<string, int> pair in dictionary){ // 이건 또 뭐고
				Console.WriteLine("[" + pair.Key + "] :" + pair.Value + "points");
			}
		}
	}
}
```

----

# C# 인터페이스

## C# 가상 키워드

- 기본적으로 가상 키워드(Virtual)로 가상 클래스 등을 정의하여 사용할 수 있습니다.
- 가상 클래스의 기능을 자식 클래스에서 재정의해서 사용할 수 있습니다.
- 가상 클래스의 메소드는 꼭 재정의(Override)하지는 않아도 됩니다.

C++에서 배운 가상 키워드와 거의 동일하다.
-


```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Monster{
	public string name;
	public virtual void Attack(){ // 재정의 할 수도 있고 안할 수도 있다.
		Console.WriteLine("Attack! ");
	}
}

public class Ork : Monster{
	public override void Attack(){ // override로 재정의한다.
		base.Attack(); // base는 부모 클래스를 의미한다.
		name = "Head Ork";
		Console.WriteLine(name + ": Ork's Attack");
	}
}


namespace ConsoleApp1 {
	class Program {
		static void Main(string[] args){
			Monster monster = new Monster();
			monster.Attack();
			Ork ork = new Ork();
			ork.Attack();
		}
	}
}
```

## C# 추상 키워드

- 추상 키워드(Abstract)는 구현해야 할 기능의 이름만 명세하고, 실제 구현은 자식 클래스에서 구현합니다.
- 추상 클래스는 인스턴스화 할 수 없으며, **자식 클래스는 기능을 반드시 구현해야 합니다.**

```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public abstract class Monster{
	public abstract void Attack();
}

public class Ork : Monster{
	public override void Attack(){
		Console.WriteLine("Ork's Attack");
	}
}


namespace ConsoleApp1 {
	class Program {
		static void Main(string[] args){
			// 추상 클래스는 인스턴스를 사용할 수 없다.
			// Monster monster = new Monster();
			// monster.Attack;

			Ork ork = new Ork();
			ork.Attack();
		}
	}
}
```


## **C# 인터페이스(매우 중요)**

- C#의 인터페이스(Interface)는 추상 클래스와 흡사합니다.
- 즉, interface를 정의하면, 그것을 상속받는 child class에서 반드시 인터페이스의 메서드를 재정의 해야합니다.
- C#의 인터페이스는 기본적으로 멤버 변수를 사용할 수 없습니다.
- **C# 인터페이스는 다중 상속이 가능합니다.**
- 인터페이스는 프로그램의 설계 목적으로 사용할 수 있습니다.
- 인터페이스는 추상 클래스와 다르게 계층적인 구조(Super-child class 관계)가 아니더라도, 같은 기능을 추가하고 싶을 때 사용합니다.


```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public interface Monster{
	void Attack();
	void Defense();
}

public class Ork : Monster{
	public void Attack(){
		Console.WriteLine("Ork's Attack");
	}
	public void Defense(){
		Console.WriteLine("Ork's Defense");
	}
}


namespace ConsoleApp1 {
	class Program {
		static void Main(string[] args){
			Ork ork = new Ork();
			ork.Attack();
			ork.Defense();
		}
	}
}
```

----

# C# .Net Framework

- .Net은 윈도우 응용 프로그램 개발 및 실행 환경을 의미합니다.
- C#이 동작할 수 있는 플랫폼(Platform)이 .Net입니다.
- C#는 C++과 자바(Java)의 장점을 수용하며 만들어졌습니다.
- 일반적인 웹, 모바일에서 약세를 보이나 윈도우 응용 프로그램 및 게임 개발에서는 여전히 입지가 있습니다.
- Unity를 이용해서 모바일 어플리케이션 개발도 가능하다.

## 공통 언어 런타임(Common Language Runtime)

- Visual Studio는 컴파일러가 작성된 소스코드를 CIL(공통 중간 언어)로 변환합니다.
- 각 컴퓨터에 존재하는 CLR은, 바이트 코드 형태인 CIL을 읽어 운영체제가 실행시킬 수 있는 Native Code로 변환합니다.
- CLR은 .Net 가상 머신의 주요 구성품입니다.
- ‘소프트웨어는 단 한 번만 작성해 만들어, 어디에서나 그대로 사용할 수 있도록 하자.’
- 즉 .Net Framework가 설치된 컴퓨터에서는 개발환경과 다르더라도 프로그램을 동작시킬 수 있다. (Java 가상머신과 동일)

C# -> 소스 코드(Source Code) -> 바이트 코드(Byte Code) CIL(exe 파일등) -> CLR -> Native Code
컴파일 시간(Compile Time) 												실행 시간(Run Time)


## .Net Framework의 장점

- CLR만 있다면 동일한 바이트 코드(CLI)를 다양한 컴퓨터 환경에서 실행시킬 수 있습니다.
- 따라서 일반적으로 생산 효율성이 요구되고, 대기 시간이 많은 클라이언트 UI를 개발할 때 유리합니다.
- 응용 프로그램 뿐만 아니라 ASP.Net과 같은 웹 애플리케이션 개발 기술도 제공합니다. 웹서버등에 유용하다.


## .Net Framework의 단점

- C/C++에 비해서 메모리 요구량이 많고, 처리 속도가 느리다는 단점이 있습니다.
- .Net 응용 프로그램을 실행하기 위해서는 컴퓨터에 .Net Framework를 설치해야 합니다.


## 구성도

Visual Studio C#개발 환경 -> 컴파일 -> .exe 프로그램		-> 	.Net Framework												->네이티브기계어 코드, 실행
C# 소스코드					 			CIL 메타데이터			JIT 컴파일러,CLR Security등 <-> .Net Framework 라이브러리
리소스 및 참조
컴파일러

----


# Visual C#의 주요 컴포넌트

```
private void add_Click(object sender, EventArgs e){
	int result = Convert.ToInt32(variable1.Text) + Convert.ToInt32(variable2.Text);
	resultLabel.Text = Convert.ToString(result);
}
private void subtract_Click(object sender, EventArgs e){
	int result = Convert.ToInt32(variable1.Text) - Convert.ToInt32(variable2.Text);
	resultLabel.Text = Convert.ToString(result);
}
private void multiple_Click(object sender, EventArgs e){
	int result = Convert.ToInt32(variable1.Text) * Convert.ToInt32(variable2.Text);
	resultLabel.Text = Convert.ToString(result);
}
private void divide_Click(object sender, EventArgs e){
	int result = Convert.ToInt32(variable1.Text) / Convert.ToInt32(variable2.Text);
	resultLabel.Text = Convert.ToString(result);
}

```

이걸 고치면,
```
public Form1(){
	InitializeComponent();
	// 연산을 기록하는 객체를 생성. 원소 목록이 화면에 출력되게 한다.
	resultListView.View = View.Details;
	resultListView.Columns.Add("기록", 240);
}

private void add_Click(object sender, EventArgs e){
	try	{
		int result = Convert.ToInt32(variable1.Text) + Convert.ToInt32(variable2.Text);
		resultLabel.Text = Convert.ToString(result);
		// 연산 기록
		ListViewItem item = new ListViewItem(variable1.Text + " + " + variable2.Text + " = " + result);
		resultListView.Items.Add(item);
	} catch (Exception)	{
	resultLabel.Text = "입력 값 오류가 발생했습니다.";
	}
}
```


# Visual C#의 주요 이벤트

MouseHover, MouseLeave는 영역에 마우스가 들어오고 나갈때

```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// parentform에서 childform으로 데이터를 전달할 때에는 interface를 많이 사용한다.
namespace WindowsFormsApp3{
	public interface DataTransferInterface{
		void transfer(string data); //
	}
}

public partial class ParentForm : Form, DataTransferInterface {
	public ParentForm()	{
		InitializeComponent();
	}
	
	// DataTransferInterface에 있는 transfer함수를 사용할 수 있게 한다.
	private void openChildForm_Click(object sender, EventArgs e){
		// 자식 폼에 부모 폼의 값을 매개변수로 넣다.
		// DataTransferInterface로 parentform의 instance를 보낸다.
		ChildForm childForm = new ChildForm(this as DataTransferInterface);
		childForm.Show();
	}
	
	private void openChildForm_MouseHover(object sender, EventArgs e){
		openChildForm.Text = "클릭하세요.";
	}
	
	private void openChildForm_MouseLeave(object sender, EventArgs e){
		openChildForm.Text = "가지마세요.";
	}
	
	// 가져온 transfer 재정의
	public void transfer(String data){
		dataLabel.Text = data;
	}
}

public partial class ChildForm : Form
{
	private DataTransferInterface dataTransferInterface = null;
	
	public ChildForm(DataTransferInterface dataTransferInterface){
		InitializeComponent();
		this.dataTransferInterface = dataTransferInterface;
		transferButton.Enabled = false;
	}
	
	private void dataTextBox_TextChanged(object sender, EventArgs e){
		if(dataTextBox.Text.Length >= 6){
			statusLabel.Text = "전송해주세요.";
			transferButton.Enabled = true;
		} else {
			statusLabel.Text = "너무 짧습니다.";
			transferButton.Enabled = false;
		}
	}
	
	private void transferButton_Click(object sender, EventArgs e){
		dataTransferInterface.transfer(dataTextBox.Text);
		Close();
	}
}
```