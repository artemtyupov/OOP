#pragma once
#include "entrypoint.h"
#include <math.h>

namespace src {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pbScreen;
	private: System::Windows::Forms::TextBox^  txtScale;
	private: System::Windows::Forms::OpenFileDialog^  dlgOpen;
	private: System::Windows::Forms::Button^  btnOpen;
	private: System::Windows::Forms::Button^  btnScale;
	private: System::Windows::Forms::Button^  btnRotate;
	private: System::Windows::Forms::Button^  btnShift;
	private: System::Windows::Forms::TextBox^  txtAngX;
	private: System::Windows::Forms::TextBox^  txtAngY;
	private: System::Windows::Forms::TextBox^  txtDx;
	private: System::Windows::Forms::TextBox^  txtDy;
	private: System::Windows::Forms::TextBox^  txtDz;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  txtAngZ;
	private: System::Windows::Forms::Button^  btnSetRot;
	protected: 

	protected: 













	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pbScreen = (gcnew System::Windows::Forms::PictureBox());
			this->txtScale = (gcnew System::Windows::Forms::TextBox());
			this->dlgOpen = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->btnScale = (gcnew System::Windows::Forms::Button());
			this->btnRotate = (gcnew System::Windows::Forms::Button());
			this->btnShift = (gcnew System::Windows::Forms::Button());
			this->txtAngX = (gcnew System::Windows::Forms::TextBox());
			this->txtAngY = (gcnew System::Windows::Forms::TextBox());
			this->txtDx = (gcnew System::Windows::Forms::TextBox());
			this->txtDy = (gcnew System::Windows::Forms::TextBox());
			this->txtDz = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtAngZ = (gcnew System::Windows::Forms::TextBox());
			this->btnSetRot = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbScreen))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// pbScreen
			// 
			this->pbScreen->BackColor = System::Drawing::Color::AliceBlue;
			this->pbScreen->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbScreen->Location = System::Drawing::Point(12, 12);
			this->pbScreen->Name = L"pbScreen";
			this->pbScreen->Size = System::Drawing::Size(640, 480);
			this->pbScreen->TabIndex = 3;
			this->pbScreen->TabStop = false;
			this->pbScreen->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pbScreen_MouseDown);
			this->pbScreen->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pbScreen_MouseMove);
			this->pbScreen->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pbScreen_MouseUp);
			// 
			// txtScale
			// 
			this->txtScale->Location = System::Drawing::Point(6, 6);
			this->txtScale->Name = L"txtScale";
			this->txtScale->Size = System::Drawing::Size(50, 20);
			this->txtScale->TabIndex = 4;
			this->txtScale->Text = L"1,0";
			// 
			// dlgOpen
			// 
			this->dlgOpen->FileName = L"empty";
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(686, 32);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(75, 23);
			this->btnOpen->TabIndex = 5;
			this->btnOpen->Text = L"Открыть...";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &Form1::btnOpen_Click);
			// 
			// btnScale
			// 
			this->btnScale->Location = System::Drawing::Point(68, 6);
			this->btnScale->Name = L"btnScale";
			this->btnScale->Size = System::Drawing::Size(118, 23);
			this->btnScale->TabIndex = 6;
			this->btnScale->Text = L"Масштабировать";
			this->btnScale->UseVisualStyleBackColor = true;
			this->btnScale->Click += gcnew System::EventHandler(this, &Form1::btnScale_Click);
			// 
			// btnRotate
			// 
			this->btnRotate->Location = System::Drawing::Point(6, 81);
			this->btnRotate->Name = L"btnRotate";
			this->btnRotate->Size = System::Drawing::Size(75, 23);
			this->btnRotate->TabIndex = 6;
			this->btnRotate->Text = L"Повернуть";
			this->btnRotate->UseVisualStyleBackColor = true;
			this->btnRotate->Click += gcnew System::EventHandler(this, &Form1::btnRotate_Click);
			// 
			// btnShift
			// 
			this->btnShift->Location = System::Drawing::Point(57, 81);
			this->btnShift->Name = L"btnShift";
			this->btnShift->Size = System::Drawing::Size(86, 23);
			this->btnShift->TabIndex = 6;
			this->btnShift->Text = L"Переместить";
			this->btnShift->UseVisualStyleBackColor = true;
			this->btnShift->Click += gcnew System::EventHandler(this, &Form1::btnShift_Click);
			// 
			// txtAngX
			// 
			this->txtAngX->Location = System::Drawing::Point(89, 3);
			this->txtAngX->Name = L"txtAngX";
			this->txtAngX->Size = System::Drawing::Size(50, 20);
			this->txtAngX->TabIndex = 4;
			this->txtAngX->Text = L"0,0";
			// 
			// txtAngY
			// 
			this->txtAngY->Location = System::Drawing::Point(89, 29);
			this->txtAngY->Name = L"txtAngY";
			this->txtAngY->Size = System::Drawing::Size(50, 20);
			this->txtAngY->TabIndex = 4;
			this->txtAngY->Text = L"0,0";
			// 
			// txtDx
			// 
			this->txtDx->Location = System::Drawing::Point(89, 3);
			this->txtDx->Name = L"txtDx";
			this->txtDx->Size = System::Drawing::Size(50, 20);
			this->txtDx->TabIndex = 4;
			this->txtDx->Text = L"0,0";
			// 
			// txtDy
			// 
			this->txtDy->Location = System::Drawing::Point(89, 29);
			this->txtDy->Name = L"txtDy";
			this->txtDy->Size = System::Drawing::Size(50, 20);
			this->txtDy->TabIndex = 4;
			this->txtDy->Text = L"0,0";
			// 
			// txtDz
			// 
			this->txtDz->Location = System::Drawing::Point(89, 55);
			this->txtDz->Name = L"txtDz";
			this->txtDz->Size = System::Drawing::Size(50, 20);
			this->txtDz->TabIndex = 4;
			this->txtDz->Text = L"0,0";
			// 
			// tabControl1
			// 
			this->tabControl1->Appearance = System::Windows::Forms::TabAppearance::Buttons;
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(658, 61);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(200, 136);
			this->tabControl1->TabIndex = 7;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::Transparent;
			this->tabPage1->Controls->Add(this->txtScale);
			this->tabPage1->Controls->Add(this->btnScale);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(192, 107);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Масштаб";
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::Transparent;
			this->tabPage2->Controls->Add(this->label6);
			this->tabPage2->Controls->Add(this->label5);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->txtAngX);
			this->tabPage2->Controls->Add(this->txtAngZ);
			this->tabPage2->Controls->Add(this->txtAngY);
			this->tabPage2->Controls->Add(this->btnSetRot);
			this->tabPage2->Controls->Add(this->btnRotate);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(192, 107);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Поворот";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(48, 58);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(29, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"o Z :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(48, 32);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(29, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"o Y :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(48, 6);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(29, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"o X :";
			// 
			// txtAngZ
			// 
			this->txtAngZ->Location = System::Drawing::Point(89, 55);
			this->txtAngZ->Name = L"txtAngZ";
			this->txtAngZ->Size = System::Drawing::Size(50, 20);
			this->txtAngZ->TabIndex = 4;
			this->txtAngZ->Text = L"0,0";
			// 
			// btnSetRot
			// 
			this->btnSetRot->Location = System::Drawing::Point(111, 81);
			this->btnSetRot->Name = L"btnSetRot";
			this->btnSetRot->Size = System::Drawing::Size(75, 23);
			this->btnSetRot->TabIndex = 6;
			this->btnSetRot->Text = L"Установить";
			this->btnSetRot->UseVisualStyleBackColor = true;
			this->btnSetRot->Click += gcnew System::EventHandler(this, &Form1::btnSetRot_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::Transparent;
			this->tabPage3->Controls->Add(this->label3);
			this->tabPage3->Controls->Add(this->label2);
			this->tabPage3->Controls->Add(this->label1);
			this->tabPage3->Controls->Add(this->btnShift);
			this->tabPage3->Controls->Add(this->txtDx);
			this->tabPage3->Controls->Add(this->txtDz);
			this->tabPage3->Controls->Add(this->txtDy);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(192, 107);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Сдвиг";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(57, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(26, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"dZ :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(57, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"dY :";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(57, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"dX :";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(889, 504);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->btnOpen);
			this->Controls->Add(this->pbScreen);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbScreen))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


	private:
		Point mpos;

		System::Void pbScreen_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
			mpos.X = e->X;
			mpos.Y = e->Y;
		}
		System::Void pbScreen_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
			if (e->Button == Windows::Forms::MouseButtons::Left)
			{
#define SENSITIVITY 30.0
				double dy = (e->X - mpos.X) / SENSITIVITY;
				double dx = (e->Y - mpos.Y) / SENSITIVITY;
				mpos.X = e->X;
				mpos.Y = e->Y;

				sMove move;
				uChangeData change;
				move.dx = dx;
				move.dy = 0.0;
				move.dz = dy;
				change.move = move;
				Apply(caRotate, &change);
			}
		}

		System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
		{
			uChangeData change;
			sCanvasContainer cont;
			cont.pb = pbScreen; //инициализируем
			change.canvas = &cont;
			Apply(caInit, &change);
			change.scale = 1.0; //масштабируем
			Apply(caScale, &change);
			sMove move;
			move.dx = 45.0 / 180.0 * M_PI;
			move.dy = 0;
			move.dz = 135.0 / 180.0 * M_PI;
			change.move = move; //вращаем
			Apply(caSetRot, &change);
		}
		System::Void pbScreen_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		}
		System::Void btnOpen_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (dlgOpen->ShowDialog() != Windows::Forms::DialogResult::OK)
				return;

			uChangeData change;

			char* filename_classic = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(dlgOpen->FileName);
			change.filename = filename_classic;
			eCodeFile result = Apply(caLoad, &change);
			System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)filename_classic);

			switch (result)
			{
			case (cfFine):
				{
					break;
				}
			case (cfNotFound):
				{
					MessageBox::Show("Файл не найден!", "Ошибка", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
					break;
				}
			case (cfCorrupted):
				{
					MessageBox::Show("Файл содержит некорректные данные!", "Ошибка", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
					break;
				}
			case (cfOutOfMemory):
				{
					MessageBox::Show("Не хватает памяти для загрузки модели!", "Ошибка", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
					break;
				}
			default:
				{
					MessageBox::Show("Неизвестная ошибка!", "Ошибка", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
				}
			}

			result = Apply(caDrawMod, &change);
		}
		System::Void btnScale_Click(System::Object^  sender, System::EventArgs^  e) {
			uChangeData change;
			change.scale = Convert::ToDouble(txtScale->Text);
			Apply(caScale, &change);
		}
		System::Void btnRotate_Click(System::Object^  sender, System::EventArgs^  e)
		{
			sMove move;
			uChangeData change;
			move.dx = Convert::ToDouble(txtAngX->Text) / 180.0 * M_PI;
			move.dy = Convert::ToDouble(txtAngY->Text) / 180.0 * M_PI;
			move.dz = Convert::ToDouble(txtAngZ->Text) / 180.0 * M_PI;
			change.move = move;
			Apply(caRotate, &change);
		}
		System::Void btnSetRot_Click(System::Object^  sender, System::EventArgs^  e)
		{
			sMove move;
			uChangeData change;
			move.dx = Convert::ToDouble(txtAngX->Text) / 180.0 * M_PI;
			move.dy = Convert::ToDouble(txtAngY->Text) / 180.0 * M_PI;
			move.dz = Convert::ToDouble(txtAngZ->Text) / 180.0 * M_PI;
			change.move = move;
			Apply(caSetRot, &change);
		}
		System::Void btnShift_Click(System::Object^  sender, System::EventArgs^  e)
		{
			sMove move;
			uChangeData change;
			move.dx = Convert::ToDouble(txtDx->Text);
			move.dy = Convert::ToDouble(txtDy->Text);
			move.dz = Convert::ToDouble(txtDz->Text);
			change.move = move;
			Apply(caShift, &change);
		}
};
}

