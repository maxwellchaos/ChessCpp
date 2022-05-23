#pragma once
#include <cmath>
#include <fstream>
#include<iostream>
#include <windows.h>


//Класс окна интерфейса
//тут только интерфейс, правильность ходов и ИИ в других классах

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			bmp = (gcnew System::Drawing::Bitmap(1000, 1000));
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button1;

	private: System::Drawing::Bitmap^ bmp;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Right;
			this->pictureBox1->Location = System::Drawing::Point(487, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(161, 184);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Left;
			this->pictureBox2->Location = System::Drawing::Point(0, 0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(172, 184);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox2_Paint);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(280, 71);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(280, 125);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(361, 32);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(648, 184);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


		double gg[40];
		int x = 1;
		gg[0] = 0;
		for (; x < 40;x++) 
		{
			gg[x] = gg[x - 1] + 3.14 / 80;
		}
		for (int v =0; v < 40; v = v+2)
		{
			dygovoyBatya(100, 120, gg[v - 1], gg[v]);
		}
		//for (int i = 100; i > 0; i--)
		//{
		//	bmp->SetPixel(i, 0, Color::Black);
		//	/*bmp->SetPixel(i, 2, Color::Black);
		//	bmp->SetPixel(i, 4, Color::Black);*/
		//}

		//for (int i = 100; i > 0; i--)
		//{
		//	bmp->SetPixel(0, i, Color::Black);
		//	bmp->SetPixel(2, i, Color::Black);
		//	bmp->SetPixel(4, i, Color::Black);
		//}
		/*dygovoyBatya(120,140 , 3.14 / 6, 3.14 / 3);
		dygovoyBatya(100, 120, 3.14/3, 3.14/2);
		dygovoyBatya(100, 120, 0, 3.14/6);*/
		pictureBox2->Invalidate();
		/*for (int a = 0, R1 = 49; a < 150; a++)
		{
			for (int b = 0, R2 = 149; b < 150; b++)
			{

					bmp->SetPixel(b, a, Color::DarkRed);
			}
		}*/
	}
	private: System::Void pictureBox2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		/*e->Graphics->DrawEllipse(Pens::Black,1,1,105,105);
		e->Graphics->DrawLine(Pens::DarkRed, 0, 0, 100, 100);
		e->Graphics->DrawRectangle(Pens::Black, 1, 1, 105, 105);
		e->Graphics->DrawLine(Pens::DarkRed, 100, 0, 0, 100);*/

		e->Graphics->DrawImage(bmp, 0, 0);
	}

	HANDLE hSerial = 0;
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//Работа с ком портом
		//взять отсюда: https://blablacode.ru/programmirovanie/392

		if (hSerial == 0)
		{
			LPCTSTR sPortName = L"COM3";
			hSerial = ::CreateFile(sPortName, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
			if (hSerial == INVALID_HANDLE_VALUE)
			{
				DWORD Err = GetLastError();
				if (Err == ERROR_FILE_NOT_FOUND)
				{
					button2->Text = "serial port does not exist.\n";
				}
				button2->Text = "some other error occurred.\n";
			}

			DCB dcbSerialParams = { 0 };
			dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
			if (!GetCommState(hSerial, &dcbSerialParams))
			{

			}
			dcbSerialParams.BaudRate = CBR_4800;
			dcbSerialParams.ByteSize = 8;
			dcbSerialParams.StopBits = ONESTOPBIT;
			dcbSerialParams.Parity = NOPARITY;
			if (!SetCommState(hSerial, &dcbSerialParams))
			{

			}
		}
		unsigned char data = (unsigned char)numericUpDown1->Value; // строка для передачи
		DWORD dwSize = sizeof(data);   // размер этой строки
		DWORD dwBytesWritten;

		//отправка
		BOOL iRet = WriteFile(hSerial, &data, dwSize, &dwBytesWritten, NULL);


		pictureBox2->Invalidate();
	}
	private: void dygovoyBatya(int r1, int r2, double x, double y)
	{
		//координаты центра
		//double p = 3.14/4;
		//чтобы рисовать круг
		for (int a = 0; a < 150; a++)
		{
			for (int b = 0; b < 150; b++)
			{
				if (r2 * r2 > a * a + b * b && a * a + b * b > r1 * r1)
				{
					if (b != 0)
					{
						//преобразование к типу double
						double dA = a;
						double dB = b;
						//вычисление угла из отношения катетов 
						double angle = atan(dB / dA);
						//говорит, закрашивать пиксель, или нет
						//определяет углы к радианах
						if (angle > (x ) && angle < (y))
						{
							bmp->SetPixel(a, b, Color::Red);
						}
					}
				}
			}
		}
	}
	};
}

	


//a = AB/OA
//a = tg(b)
//b = arctg(a)
