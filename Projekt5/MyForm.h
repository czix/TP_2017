#pragma once

namespace Projekt5 {

	int ax = 618; 
	int bx = 695;                                                                               
	int cx=776;
	int dx=853;
	int ay= 497;
	int by=497;
	int cy=497;
	int dy=497;
	int hakx = 500;
	int haky = -900;
	int polozone = 0;
	int done_a = 0;
	int done_b = 0;
	int done_c = 0;
	int done_d = 0;
	int wysokosc = 30 * (done_a + done_b + done_c + done_d);

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:String ^ a;
			String ^ b;
			String ^ c;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Timer^  timer4;
	private: System::Windows::Forms::Timer^  timer5;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
			 String ^ d;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Wymagana metoda obs³ugi projektanta — nie nale¿y modyfikowaæ 
		/// zawartoœæ tej metody z edytorem kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer5 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(24, -1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(385, 407);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->textBox2->Location = System::Drawing::Point(776, 497);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(57, 23);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"c";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->textBox5->Location = System::Drawing::Point(695, 497);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(57, 23);
			this->textBox5->TabIndex = 5;
			this->textBox5->Text = L"b";
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// textBox9
			// 
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->textBox9->Location = System::Drawing::Point(853, 497);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(57, 23);
			this->textBox9->TabIndex = 7;
			this->textBox9->Text = L"d";
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox9_TextChanged);
			// 
			// textBox10
			// 
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->textBox10->Location = System::Drawing::Point(618, 497);
			this->textBox10->MaximumSize = System::Drawing::Size(1000, 10000);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(57, 23);
			this->textBox10->TabIndex = 6;
			this->textBox10->Text = L"a";
			this->textBox10->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox10_TextChanged);
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(670, 614);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"AUTO";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(618, 559);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(57, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"up";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(695, 559);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(57, 23);
			this->button3->TabIndex = 10;
			this->button3->Text = L"up";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(853, 559);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(57, 23);
			this->button4->TabIndex = 12;
			this->button4->Text = L"up";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(776, 559);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(57, 23);
			this->button5->TabIndex = 11;
			this->button5->Text = L"up";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// timer2
			// 
			this->timer2->Interval = 1;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Interval = 1;
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			// 
			// timer4
			// 
			this->timer4->Interval = 1;
			this->timer4->Tick += gcnew System::EventHandler(this, &MyForm::timer4_Tick);
			// 
			// timer5
			// 
			this->timer5->Interval = 1;
			this->timer5->Tick += gcnew System::EventHandler(this, &MyForm::timer5_Tick);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(500, -900);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(63, 1162);
			this->pictureBox2->TabIndex = 13;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1203, 674);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	


		void podnies_a()
		{
			
			if ((hakx != ax || haky != ay - 1160) && (ax>430 || ay<390 - wysokosc))
			{
				hak(ax, ay);
			}
			else
			{

		
			if (ay > 100 && ax>600)
			{				
				ay--;
			}
			else
			{
				if (ax > 430)
				{
					ax--;
				}
				else
				{
					if (ay<390 - wysokosc)
					{
						ay++;
					}
					else
					{
						if (haky > -900)
						{
							haky--;
						}
						else
						{
							if (hakx < 500)
							{
								hakx++;
							}
							else
							{
								done_a = 1;
							}
						}
					}
				}
			}
			}

			this->textBox10->Location = System::Drawing::Point(ax, ay);
			this->pictureBox2->Location = System::Drawing::Point(hakx, haky);
			
		};

		void podnies_b()
		{

			if ((hakx != bx || haky != by - 1160) && (bx>430 || by<390 - wysokosc))
			{
				hak(bx, by);
			}
			else
			{

			if (by > 100 && bx>600)
			{
				by--;
			}
			else
			{
				if (bx > 430)
				{
					bx--;
				}
				else
				{
					if (by<390 - wysokosc)
					{
						by++;
					}
					else
					{
						if (haky > -900)
						{
							haky--;
						}
						else
						{
							if (hakx < 500)
							{
								hakx++;
							}
							else
							{
								done_b = 1;
							}
						}
					}
				}
			}
			}

			this->textBox5->Location = System::Drawing::Point(bx, by);
			this->pictureBox2->Location = System::Drawing::Point(hakx, haky);

		};


		void podnies_c()
		{

			if ((hakx != cx || haky != cy - 1160) && (cx>430 || cy<390 - wysokosc))
			{
				hak(cx, cy);
			}
			else
			{

			if (cy > 100 && cx>600)
			{
				cy--;
			}
			else
			{
				if (cx > 430)
				{
					cx--;
				}
				else
				{
					if (cy<390 - wysokosc)
					{
						cy++;
					}
					else
					{
						if (haky > -900)
						{
							haky--;
						}
						else
						{
							if (hakx < 500)
							{
								hakx++;
							}
							else
							{
								done_c = 1;
							}
						}
					}
				}
			}
			}


			this->textBox2->Location = System::Drawing::Point(cx, cy);
			this->pictureBox2->Location = System::Drawing::Point(hakx, haky);

		};


		void podnies_d()
		{
			if ((hakx != dx || haky != dy - 1160) && (dx>430 || dy<390-wysokosc))
			{
				hak(dx, dy);
			}
			else
			{

				if (dy > 100 && dx > 600)
				{
					dy--;

				}
				else
				{
					if (dx > 430)
					{
						dx--;

					}
					else
					{
						if (dy < 390 - wysokosc)
						{
							dy++;

						}
						else
						{
							if (haky > -900)
							{
								haky--;
							}
							else
							{
								if (hakx < 500)
								{
									hakx++;
								}
								else
								{
									done_d = 1;
								}
							}
						}
					}
				}
			}

			this->textBox9->Location = System::Drawing::Point(dx, dy);
			this->pictureBox2->Location = System::Drawing::Point(hakx, haky);
		};





		void hak(int x ,int y)
		{
			if (hakx > x)
			{
				hakx--;
			}

			if (hakx < x)
			{
				hakx++;
			}
			if (haky > y-1160)
			{
				haky--;
			}

			if (haky < y-1160)
			{
				haky++;
			}

		};





private: System::Void textBox10_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	
	String ^ a = textBox10->Text;

}
private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	String ^ b = textBox5->Text;
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	String ^ c = textBox2->Text;
}
private: System::Void textBox9_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	String ^ d = textBox9->Text;
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	a = textBox10->Text;
	b = textBox5->Text;
	c = textBox2->Text;
	d = textBox9->Text;
	this->timer1->Start();
		
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	wysokosc = 30 * (done_a + done_b + done_c + done_d);
	if (a == "kwadrat" && done_a == 0 && wysokosc < 90)
	{
		podnies_a();
	}
	else
	{
		if (b == "kwadrat" && done_b == 0 && wysokosc < 90)
		{
			podnies_b();
		}
		else
		{
			if (c == "kwadrat" && done_c == 0 && wysokosc < 90)
			{
				podnies_c();
			}
			else
			{
				if (d == "kwadrat" && done_d == 0 && wysokosc < 90)
				{
					podnies_d();
				}
				else
				{
					this->timer1->Stop();
				}
			}
		}
	}


	

}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	a = textBox10->Text;
	this->timer2->Start();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	b = textBox5->Text;
	this->timer3->Start();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	c = textBox2->Text;
	this->timer4->Start();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	d = textBox9->Text;
	this->timer5->Start();
}
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
	wysokosc = 30 * (done_a + done_b + done_c + done_d);
	if (a == "kwadrat" && done_a == 0 && wysokosc < 90)
	{
		podnies_a();
	}
	else
	{
		this->timer2->Stop();
	}
}
private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
	wysokosc = 30 * (done_a + done_b + done_c + done_d);
	if (b == "kwadrat" && done_b == 0 && wysokosc < 90)
	{
		podnies_b();
	}
	else
	{
		this->timer3->Stop();
	}
}
private: System::Void timer4_Tick(System::Object^  sender, System::EventArgs^  e) {
	wysokosc = 30 * (done_a + done_b + done_c + done_d);
	if (c == "kwadrat" && done_c == 0 && wysokosc <90)
	{
		podnies_c();
	}
	else
	{
		this->timer4->Stop();
	}
}
private: System::Void timer5_Tick(System::Object^  sender, System::EventArgs^  e) {
	wysokosc = 30 * (done_a + done_b + done_c + done_d);
	if (d == "kwadrat" && done_d== 0 && wysokosc < 90)
	{
		podnies_d();
	}
	else
	{
		this->timer5->Stop();
	}
}
private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}

