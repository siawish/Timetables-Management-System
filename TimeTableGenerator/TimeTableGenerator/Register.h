#pragma once

namespace TimeTableGenerator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Home
	/// </summary>
	public ref class Home : public System::Windows::Forms::Form
	{
	public:
		Home(void)
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
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ Firstnametb;

	private: System::Windows::Forms::TextBox^ Lastnametb;
	private: System::Windows::Forms::TextBox^ Usernametb;
	private: System::Windows::Forms::TextBox^ Emailtb;
	private: System::Windows::Forms::TextBox^ Passwordtb;
	private: System::Windows::Forms::TextBox^ ConfirmPasstb;






	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ Signupbtn;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Firstnametb = (gcnew System::Windows::Forms::TextBox());
			this->Lastnametb = (gcnew System::Windows::Forms::TextBox());
			this->Usernametb = (gcnew System::Windows::Forms::TextBox());
			this->Emailtb = (gcnew System::Windows::Forms::TextBox());
			this->Passwordtb = (gcnew System::Windows::Forms::TextBox());
			this->ConfirmPasstb = (gcnew System::Windows::Forms::TextBox());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Signupbtn = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(470, 59);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 42);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Register";
			this->label1->Click += gcnew System::EventHandler(this, &Home::label1_Click);
			// 
			// Firstnametb
			// 
			this->Firstnametb->Location = System::Drawing::Point(292, 172);
			this->Firstnametb->Margin = System::Windows::Forms::Padding(4);
			this->Firstnametb->Name = L"Firstnametb";
			this->Firstnametb->Size = System::Drawing::Size(199, 26);
			this->Firstnametb->TabIndex = 4;
			// 
			// Lastnametb
			// 
			this->Lastnametb->Location = System::Drawing::Point(803, 172);
			this->Lastnametb->Margin = System::Windows::Forms::Padding(4);
			this->Lastnametb->Name = L"Lastnametb";
			this->Lastnametb->Size = System::Drawing::Size(199, 26);
			this->Lastnametb->TabIndex = 5;
			// 
			// Usernametb
			// 
			this->Usernametb->Location = System::Drawing::Point(292, 224);
			this->Usernametb->Margin = System::Windows::Forms::Padding(4);
			this->Usernametb->Name = L"Usernametb";
			this->Usernametb->Size = System::Drawing::Size(199, 26);
			this->Usernametb->TabIndex = 6;
			// 
			// Emailtb
			// 
			this->Emailtb->Location = System::Drawing::Point(803, 221);
			this->Emailtb->Margin = System::Windows::Forms::Padding(4);
			this->Emailtb->Name = L"Emailtb";
			this->Emailtb->Size = System::Drawing::Size(199, 26);
			this->Emailtb->TabIndex = 7;
			// 
			// Passwordtb
			// 
			this->Passwordtb->Location = System::Drawing::Point(292, 277);
			this->Passwordtb->Margin = System::Windows::Forms::Padding(4);
			this->Passwordtb->Name = L"Passwordtb";
			this->Passwordtb->Size = System::Drawing::Size(199, 26);
			this->Passwordtb->TabIndex = 8;
			// 
			// ConfirmPasstb
			// 
			this->ConfirmPasstb->Location = System::Drawing::Point(803, 274);
			this->ConfirmPasstb->Margin = System::Windows::Forms::Padding(4);
			this->ConfirmPasstb->Name = L"ConfirmPasstb";
			this->ConfirmPasstb->Size = System::Drawing::Size(199, 26);
			this->ConfirmPasstb->TabIndex = 9;
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(1121, 498);
			this->linkLabel1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(50, 20);
			this->linkLabel1->TabIndex = 10;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Login";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(918, 498);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(207, 20);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Already Have an Account\?";
			// 
			// Signupbtn
			// 
			this->Signupbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Signupbtn->Location = System::Drawing::Point(526, 377);
			this->Signupbtn->Margin = System::Windows::Forms::Padding(4);
			this->Signupbtn->Name = L"Signupbtn";
			this->Signupbtn->Size = System::Drawing::Size(150, 41);
			this->Signupbtn->TabIndex = 12;
			this->Signupbtn->Text = L"SignUp";
			this->Signupbtn->UseVisualStyleBackColor = true;
			this->Signupbtn->Click += gcnew System::EventHandler(this, &Home::Signupbtn_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(188, 178);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 20);
			this->label3->TabIndex = 13;
			this->label3->Text = L"First Name";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(649, 172);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 20);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Last Name";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(190, 230);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(86, 20);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Username";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(660, 224);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(51, 20);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Email";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(190, 283);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(83, 20);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Password";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(617, 277);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(147, 20);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Confirm Password";
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1193, 545);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Signupbtn);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->ConfirmPasstb);
			this->Controls->Add(this->Passwordtb);
			this->Controls->Add(this->Emailtb);
			this->Controls->Add(this->Usernametb);
			this->Controls->Add(this->Lastnametb);
			this->Controls->Add(this->Firstnametb);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Home";
			this->Text = L"Register";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Signupbtn_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
