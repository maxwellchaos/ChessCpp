#pragma once
#include <cmath>
#include <fstream>
#include<iostream>
#include <windows.h>
#include "Field.h"
#include "AI.h"
#include "FigureMove.h"


//����� ���� ����������
//��� ������ ���������, ������������ ����� � �� � ������ �������

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		//������ ����� ������ ���� �� �����
		//����������� ��� ��������� � ���������� ��������� �����
		const int fieldSize = 70;
		MyForm(void)
		{
			InitializeComponent();
			bmp = (gcnew System::Drawing::Bitmap(1000, 1000));

			//�������� �������� ����
			field = new Field();
			ai = new AI();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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



		   //������� ���� ��� ������
	private: Field* field;
	

	private: AI* ai;

	private:int blackWins = 0;
	private:int whiteWins = 0;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;


	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
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
			this->pictureBox2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox2_MouseDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(741, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 26);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(746, 94);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 37);
			this->button1->TabIndex = 5;
			this->button1->Text = L"������ �������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(746, 161);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(746, 178);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"label3";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1149, 743);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			pictureBox2->Invalidate();
		}
	private: System::Void pictureBox2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
		{
			//������� ����� ����� � ������
			label2->Text = "�o��� �����: " + whiteWins.ToString();
			label3->Text = "�o��� ������: " + blackWins.ToString();
			//����� ��� ��������� ������� ������
			//������ �������� ���� � �������
			//	���� ^ - ��� ������ ��� ��������� - ����������� ���������.
			Brush^ b = Brushes::Black;
			//����� ��� ���������
			Brush^ SelectedBrush = gcnew SolidBrush(Color::FromArgb(100, 255, 0, 0));
			//����� ��� ��������� ������� ������ 
			Brush^ SelectedFigureBrush = gcnew SolidBrush(Color::FromArgb(170, 0, 255, 0));
			//��������� ��� ������
			for (int i = 0; i < 8; i++)
			{
				//������ ������ ������� � ������������ �����
				if (b == Brushes::Black)
				{
					b = Brushes::White;
				}
				else
				{
					b = Brushes::Black;
				}
				//��������� ��� ������� � � �����
				for (int j = 0; j < 8; j++)
				{
					//������ ����� ������� ����� ����, ����� ���������� ����������� ������� � ������
					if (b == Brushes::Black)
					{
						b = Brushes::White;
					}
					else
					{
						b = Brushes::Black;
					}
					//����� ������ ����
					e->Graphics->FillRectangle(b, j * fieldSize, i * fieldSize, fieldSize, fieldSize);

					//����� ���������, ���� ��� ����
					if (field->Moves[i][j])
					{
						e->Graphics->FillRectangle(SelectedBrush, j * fieldSize, i * fieldSize, fieldSize, fieldSize);
					}
					//����� ��������� ������, ���� ��� ����
					if (field->Figures[i][j] == field->SelectedFigure && field->SelectedFigure != nullptr)
					{
						e->Graphics->FillRectangle(SelectedFigureBrush, j * fieldSize, i * fieldSize, fieldSize, fieldSize);
					}

					//���� �� ���� ���� ���� ������, �� ����� ������
					Figure* figure = field->Figures[i][j];
					if (figure != 0)
					{
						if (figure->FigureColor == FigureColors::white)
						{
							if (figure->FigureType == FigureTypes::pawn)
							{
								Bitmap^ image1 = gcnew Bitmap("img/����� �����.png");
								//���������� �����
								e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
							}
							if (figure->FigureType == FigureTypes::rock)
							{
								Bitmap^ image1 = gcnew Bitmap("img/����� �����.png");
								e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
							}
							if (figure->FigureType == FigureTypes::queen)
							{
								Bitmap^ image1 = gcnew Bitmap("img/����� �����.png");
								e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
							}
							if (figure->FigureType == FigureTypes::knight)
							{
								Bitmap^ image1 = gcnew Bitmap("img/����� ����.png");
								e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
							}
							if (figure->FigureType == FigureTypes::king)
							{
								Bitmap^ image1 = gcnew Bitmap("img/����� ������.png");
								e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
							}
							if (figure->FigureType == FigureTypes::bishop)
							{
								Bitmap^ image1 = gcnew Bitmap("img/����� ����.png");
								e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
							}
						}
						else
						{
							if (figure->FigureType == FigureTypes::pawn)
							{
								Bitmap^ image1 = gcnew Bitmap("img/������ �����.png");
								//���������� �����
								e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
							}
							if (figure->FigureType == FigureTypes::rock)
							{
								Bitmap^ image1 = gcnew Bitmap("img/������ �����.png");
								e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
							}
							if (figure->FigureType == FigureTypes::queen)
							{
								Bitmap^ image1 = gcnew Bitmap("img/������ �����.png");
								e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
							}
							if (figure->FigureType == FigureTypes::knight)
							{
								Bitmap^ image1 = gcnew Bitmap("img/������ ����.png");
								e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
							}
							if (figure->FigureType == FigureTypes::king)
							{
								Bitmap^ image1 = gcnew Bitmap("img/������ ������.png");
								e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
							}
							if (figure->FigureType == FigureTypes::bishop)
							{
								Bitmap^ image1 = gcnew Bitmap("img/������ ����.png");
								e->Graphics->DrawImage(image1, j * fieldSize, i * fieldSize);
							}
						}
					}
				}
			}
			//�������� ��������� ���� � label1
			if (field->Checkmate)
			{
				if (field->CurrentMoveColor == FigureColors::white)
				{
					label1->Text = "��� �����";
				}
				else
				{
					label1->Text = "��� ������";
				}
			}
			else if (field->Check)
			{
				if (field->CurrentMoveColor == FigureColors::white)
				{
					label1->Text = "��� �����";
				}
				else
				{
					label1->Text = "��� ������";
				}
			}
			else
			{
				if (field->CurrentMoveColor == FigureColors::white)
				{
					label1->Text = "����� �����";
				}
				else
				{
					label1->Text = "����� ������";
				}
			}
		}

		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
		{
			pictureBox2->Invalidate();
		}

		//������� ������� ����
		//���������� ����� � ��������� e
		private: System::Void pictureBox2_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			int x = e->X;
			int y = e->Y;
			//���������� ���� �� �������� ��������
			int j = x / fieldSize;
			int i = y / fieldSize;

			if (field->SelectedFigure != nullptr)
			{
				//���� ���� ���������� ������
				if (field->Moves[i][j])
				{
					//���� ���������� ������ ����� ����� �� ������ �� ������� ��������
					//������� ���
					bool MoveResult = field->Move(i, j);
					

					if (MoveResult)
					{
						if (field->Checkmate)
						{
							if (field->CurrentMoveColor == FigureColors::white)
							{
								blackWins++;
							}
							else
							{
								whiteWins++;
							}
							return;
						}

						FigureMove * move = ai->BestMove(field, field->CurrentMoveColor);

						//������� ����
						field->Moves[move->StartI][move->StartJ] = true;
						field->Moves[move-> FinishI][move->FinishJ] = true;
						if (field->Checkmate)
						{
							if (field->CurrentMoveColor == FigureColors::white)
							{
								blackWins++;
							}
							else
							{
								whiteWins++;
							}
							return;
						}
					}
				}
				else
				{
					//���� �������� �� ������, ���� ������ �����
					SelelectNewFigure(i, j);
				}
			}
			else
			{
				//���� ��� ���������� ������
				SelelectNewFigure(i, j);
			}

			//������������ ����
			pictureBox2->Invalidate();
			return;
		}
		//����� ��� ��������� ������
		void SelelectNewFigure(int i, int j)
		{
			//���� � ������ ���� ������
			if (field->Figures[i][j] != nullptr)
			{
				//���� � ������ ���� ���, ��� ����� ������
				if (field->Figures[i][j]->FigureColor == field->CurrentMoveColor)
				{
					//�������� ������ � ���������
					field->SelectFigure(i, j);
					return;
				}
			}
			//�������� ��������� ������
			field->ClearMovesMap();
			field->SelectedFigure = nullptr;
		}
	
		private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) 
		{
			//�������� � ������������ ������� ��������
			delete field;
			delete ai;
			field = new Field();
			ai = new AI();
			pictureBox2->Invalidate();
		}
	};
}
