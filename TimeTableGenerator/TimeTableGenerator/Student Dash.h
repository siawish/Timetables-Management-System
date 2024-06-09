#pragma once

namespace TimeTableGenerator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StudentDash
	/// </summary>
	public ref class StudentDash : public System::Windows::Forms::Form
	{
	public:
		StudentDash(void)
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
		~StudentDash()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ByCoursebtn;
	protected:
	private: System::Windows::Forms::Button^ ByRoombtn;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ ByDaybtn;
	private: System::Windows::Forms::Label^ label1;

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
			this->ByCoursebtn = (gcnew System::Windows::Forms::Button());
			this->ByRoombtn = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ByDaybtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// ByCoursebtn
			// 
			this->ByCoursebtn->Location = System::Drawing::Point(317, 245);
			this->ByCoursebtn->Name = L"ByCoursebtn";
			this->ByCoursebtn->Size = System::Drawing::Size(191, 23);
			this->ByCoursebtn->TabIndex = 19;
			this->ByCoursebtn->Text = L"By Course";
			this->ByCoursebtn->UseVisualStyleBackColor = true;
			// 
			// ByRoombtn
			// 
			this->ByRoombtn->Location = System::Drawing::Point(317, 207);
			this->ByRoombtn->Name = L"ByRoombtn";
			this->ByRoombtn->Size = System::Drawing::Size(191, 23);
			this->ByRoombtn->TabIndex = 18;
			this->ByRoombtn->Text = L"By Room";
			this->ByRoombtn->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(347, 117);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 18);
			this->label2->TabIndex = 17;
			this->label2->Text = L"View Timetable";
			// 
			// ByDaybtn
			// 
			this->ByDaybtn->Location = System::Drawing::Point(317, 166);
			this->ByDaybtn->Name = L"ByDaybtn";
			this->ByDaybtn->Size = System::Drawing::Size(191, 23);
			this->ByDaybtn->TabIndex = 16;
			this->ByDaybtn->Text = L"By Day";
			this->ByDaybtn->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(266, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(297, 37);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Student DashBoard";
			// 
			// StudentDash
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(806, 361);
			this->Controls->Add(this->ByCoursebtn);
			this->Controls->Add(this->ByRoombtn);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->ByDaybtn);
			this->Controls->Add(this->label1);
			this->Name = L"StudentDash";
			this->Text = L"StudentDash";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
