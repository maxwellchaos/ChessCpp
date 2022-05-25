#pragma once
#include <cmath>
#include <fstream>
#include<iostream>
#include <windows.h>
#include "Field.h"


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

			//Создание игрового поля
			field = new Field();
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

	private: System::Windows::Forms::PictureBox^ pictureBox2;


	private: System::Drawing::Bitmap^ bmp;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;

		   //Игровое поле для шахмат
	private: Field* field;


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
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox2
			// 
			this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Left;
			this->pictureBox2->Location = System::Drawing::Point(0, 0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(721, 743);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox2_Paint);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(718, 140);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(718, 86);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1149, 743);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		pictureBox2->Invalidate();

	}
	private: System::Void pictureBox2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		int fieldSize = 70;
		Brush ^b = Brushes::Black;

		for (int i = 0; i < 8; i++)
		{
			if (b == Brushes::Black)
			{
				b = Brushes::White;
			}
			else
			{
				b = Brushes::Black;
			}

			for (int j = 0; j < 8; j++)
			{
				if (b == Brushes::Black)
				{
					b = Brushes::White;
				}
				else
				{
					b = Brushes::Black;
				}
				e->Graphics->FillRectangle(b, j * fieldSize, i * fieldSize, fieldSize, fieldSize);
				
				Figure* figure = field->Figures[i][j];
				if (figure != 0)
				{
					if (figure->FigureColor == FigureColors::white)
					{
						if (figure->FigureType == FigureTypes::pawn)
						{
							Bitmap^ image1 = gcnew Bitmap("img/белая пешка.png");
							//Нарисовать пешку
							e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
						}
						if (figure->FigureType == FigureTypes::rock)
						{
							Bitmap^ image1 = gcnew Bitmap("img/белая ладья.png");
							e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
						}
						if (figure->FigureType == FigureTypes::queen)
						{
							Bitmap^ image1 = gcnew Bitmap("img/белый ферзь.png");
							e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
						}
						if (figure->FigureType == FigureTypes::knight)
						{
							Bitmap^ image1 = gcnew Bitmap("img/белый конь.png");
							e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
						}
						if (figure->FigureType == FigureTypes::king)
						{
							Bitmap^ image1 = gcnew Bitmap("img/белый король.png");
							e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
						}
						if (figure->FigureType == FigureTypes::bishop)
						{
							Bitmap^ image1 = gcnew Bitmap("img/белый слон.png");
							e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
						}
					}
					else
					{
						if (figure->FigureType == FigureTypes::pawn)
						{
							Bitmap^ image1 = gcnew Bitmap("img/черная пешка.png");
							//Нарисовать пешку
							e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
						}
						if (figure->FigureType == FigureTypes::rock)
						{
							Bitmap^ image1 = gcnew Bitmap("img/черная ладья.png");
							e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
						}
						if (figure->FigureType == FigureTypes::queen)
						{
							Bitmap^ image1 = gcnew Bitmap("img/черный ферзь.png");
							e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
						}
						if (figure->FigureType == FigureTypes::knight)
						{
							Bitmap^ image1 = gcnew Bitmap("img/черный конь.png");
							e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
						}
						if (figure->FigureType == FigureTypes::king)
						{
							Bitmap^ image1 = gcnew Bitmap("img/черный король.png");
							e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
						}
						if (figure->FigureType == FigureTypes::bishop)
						{
							Bitmap^ image1 = gcnew Bitmap("img/черный слон.png");
							e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
						}

					}
					
				}
			}
		}

		
	}

		   HANDLE hSerial = 0;
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{


		pictureBox2->Invalidate();
	}

	};
}

	


//a = AB/OA
//a = tg(b)
//b = arctg(a)
