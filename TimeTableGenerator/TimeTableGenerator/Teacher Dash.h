#pragma once
#include"SearchBYSection.h"
#include"SearchBYRoom.h"

namespace TimeTableGenerator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TeacherDash
	/// </summary>
	public ref class TeacherDash : public System::Windows::Forms::Form
	{
	public:
		TeacherDash(void)
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
		~TeacherDash()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ ByDaybtn;
	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ ByRoombtn;




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
			this->ByDaybtn = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ByRoombtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(372, 33);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(377, 46);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Teacher DashBoard";
			// 
			// ByDaybtn
			// 
			this->ByDaybtn->Location = System::Drawing::Point(440, 187);
			this->ByDaybtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->ByDaybtn->Name = L"ByDaybtn";
			this->ByDaybtn->Size = System::Drawing::Size(255, 28);
			this->ByDaybtn->TabIndex = 11;
			this->ByDaybtn->Text = L"By Section";
			this->ByDaybtn->UseVisualStyleBackColor = true;
			this->ByDaybtn->Click += gcnew System::EventHandler(this, &TeacherDash::ByDaybtn_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(480, 127);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(154, 24);
			this->label2->TabIndex = 12;
			this->label2->Text = L"View Timetable";
			// 
			// ByRoombtn
			// 
			this->ByRoombtn->Location = System::Drawing::Point(440, 238);
			this->ByRoombtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->ByRoombtn->Name = L"ByRoombtn";
			this->ByRoombtn->Size = System::Drawing::Size(255, 28);
			this->ByRoombtn->TabIndex = 13;
			this->ByRoombtn->Text = L"By Room";
			this->ByRoombtn->UseVisualStyleBackColor = true;
			// 
			// TeacherDash
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1073, 439);
			this->Controls->Add(this->ByRoombtn);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->ByDaybtn);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"TeacherDash";
			this->Text = L"Teacher Dashboard";
			this->Load += gcnew System::EventHandler(this, &TeacherDash::TeacherDash_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void TeacherDash_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ByDaybtn_Click(System::Object^ sender, System::EventArgs^ e) {
		/*SearchBYSection^ sec = gcnew SearchBYSection(this);
		sec->Show();*/	
		this->Hide();
	}
};
}
