#pragma once

namespace TimeTableGenerator {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;

    public ref class timetable : public System::Windows::Forms::Form
    {
    private:
        System::Windows::Forms::Form^ dash;

    public:
        timetable(void)
        {
            InitializeComponent();
        }

        timetable(Form^ frm)
        {
            InitializeComponent();
            AvailableTeacherIDcb();
            AvailableRoomIDcb();
            AvailableCourseIDcb();
            AvailableSectionIDcb();
            dash = frm;
        }

    protected:
        ~timetable()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ label7;
        System::Windows::Forms::Button^ button1;
        System::Windows::Forms::Button^ saveButton;
        System::Windows::Forms::Label^ label6;
        System::Windows::Forms::Label^ label5;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::ComboBox^ SectionIDcb;
        System::Windows::Forms::ComboBox^ Daycb;
        System::Windows::Forms::ComboBox^ StartTimecb;
        System::Windows::Forms::ComboBox^ TeacherIDcb;
        System::Windows::Forms::ComboBox^ RoomIDcb;
        System::Windows::Forms::ComboBox^ CourseIDcb;

        System::ComponentModel::Container^ components;

#pragma region
        void InitializeComponent(void)
        {
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->saveButton = (gcnew System::Windows::Forms::Button());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->SectionIDcb = (gcnew System::Windows::Forms::ComboBox());
            this->Daycb = (gcnew System::Windows::Forms::ComboBox());
            this->StartTimecb = (gcnew System::Windows::Forms::ComboBox());
            this->TeacherIDcb = (gcnew System::Windows::Forms::ComboBox());
            this->RoomIDcb = (gcnew System::Windows::Forms::ComboBox());
            this->CourseIDcb = (gcnew System::Windows::Forms::ComboBox());
            this->SuspendLayout();
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(372, 104);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(71, 16);
            this->label7->TabIndex = 29;
            this->label7->Text = L"Section ID:";
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(595, 413);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 28;
            this->button1->Text = L"Back";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &timetable::button1_Click);
            // 
            // saveButton
            // 
            this->saveButton->Location = System::Drawing::Point(471, 407);
            this->saveButton->Name = L"saveButton";
            this->saveButton->Size = System::Drawing::Size(100, 30);
            this->saveButton->TabIndex = 27;
            this->saveButton->Text = L"Save";
            this->saveButton->UseVisualStyleBackColor = true;
            this->saveButton->Click += gcnew System::EventHandler(this, &timetable::saveButton_Click);
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(372, 351);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(38, 16);
            this->label6->TabIndex = 21;
            this->label6->Text = L"DAY:";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(372, 301);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(71, 16);
            this->label5->TabIndex = 20;
            this->label5->Text = L"Start Time:";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(372, 251);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(77, 16);
            this->label4->TabIndex = 19;
            this->label4->Text = L"Teacher ID:";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(372, 201);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(69, 16);
            this->label3->TabIndex = 18;
            this->label3->Text = L"Course ID:";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(372, 151);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(63, 16);
            this->label2->TabIndex = 17;
            this->label2->Text = L"Room ID:";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(409, 40);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(162, 32);
            this->label1->TabIndex = 16;
            this->label1->Text = L"ADD SLOT";
            // 
            // SectionIDcb
            // 
            this->SectionIDcb->FormattingEnabled = true;
            this->SectionIDcb->Location = System::Drawing::Point(470, 101);
            this->SectionIDcb->Name = L"SectionIDcb";
            this->SectionIDcb->Size = System::Drawing::Size(200, 24);
            this->SectionIDcb->TabIndex = 31;
            this->SectionIDcb->SelectedIndexChanged += gcnew System::EventHandler(this, &timetable::SectionIDcb_SelectedIndexChanged);
            // 
            // Daycb
            // 
            this->Daycb->FormattingEnabled = true;
            this->Daycb->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"MONDAY", L"TUESDAY", L"WEDNESDAY", L"THURSDAY", L"FRIDAY" });
            this->Daycb->Location = System::Drawing::Point(472, 348);
            this->Daycb->Name = L"Daycb";
            this->Daycb->Size = System::Drawing::Size(200, 24);
            this->Daycb->TabIndex = 34;
            // 
            // StartTimecb
            // 
            this->StartTimecb->FormattingEnabled = true;
            this->StartTimecb->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"8:00:00", L"9:00:00", L"10:00:00", L"11:00:00" });
            this->StartTimecb->Location = System::Drawing::Point(472, 298);
            this->StartTimecb->Name = L"StartTimecb";
            this->StartTimecb->Size = System::Drawing::Size(200, 24);
            this->StartTimecb->TabIndex = 33;
            // 
            // TeacherIDcb
            // 
            this->TeacherIDcb->FormattingEnabled = true;
            this->TeacherIDcb->Location = System::Drawing::Point(470, 248);
            this->TeacherIDcb->Name = L"TeacherIDcb";
            this->TeacherIDcb->Size = System::Drawing::Size(200, 24);
            this->TeacherIDcb->TabIndex = 32;
            // 
            // RoomIDcb
            // 
            this->RoomIDcb->FormattingEnabled = true;
            this->RoomIDcb->Location = System::Drawing::Point(470, 148);
            this->RoomIDcb->Name = L"RoomIDcb";
            this->RoomIDcb->Size = System::Drawing::Size(200, 24);
            this->RoomIDcb->TabIndex = 30;
            // 
            // CourseIDcb
            // 
            this->CourseIDcb->FormattingEnabled = true;
            this->CourseIDcb->Location = System::Drawing::Point(470, 198);
            this->CourseIDcb->Name = L"CourseIDcb";
            this->CourseIDcb->Size = System::Drawing::Size(200, 24);
            this->CourseIDcb->TabIndex = 31;
            // 
            // timetable
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1067, 554);
            this->Controls->Add(this->SectionIDcb);
            this->Controls->Add(this->Daycb);
            this->Controls->Add(this->StartTimecb);
            this->Controls->Add(this->TeacherIDcb);
            this->Controls->Add(this->RoomIDcb);
            this->Controls->Add(this->CourseIDcb);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->saveButton);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"timetable";
            this->Text = L"timetable";
            this->Load += gcnew System::EventHandler(this, &timetable::timetable_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private:
        void AvailableTeacherIDcb()
        {
            String^ connectionString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            conn->Open();
            SqlCommand^ cmd = gcnew SqlCommand("SELECT TeacherID FROM [Teacher]", conn);
            SqlDataReader^ reader = cmd->ExecuteReader();
            while (reader->Read())
            {
                TeacherIDcb->Items->Add(reader["TeacherID"]->ToString());
            }
            reader->Close();
            conn->Close();
        }

        void AvailableRoomIDcb()
        {
            String^ connectionString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            conn->Open();
            SqlCommand^ cmd = gcnew SqlCommand("SELECT RoomID FROM Room", conn);
            SqlDataReader^ reader = cmd->ExecuteReader();
            while (reader->Read())
            {
                RoomIDcb->Items->Add(reader["RoomID"]->ToString());
            }
            reader->Close();
            conn->Close();
        }

        void AvailableCourseIDcb()
        {
            String^ connectionString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";

            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            conn->Open();
            SqlCommand^ cmd = gcnew SqlCommand("SELECT CourseID FROM Course", conn);
            SqlDataReader^ reader = cmd->ExecuteReader();
            while (reader->Read())
            {
                CourseIDcb->Items->Add(reader["CourseID"]->ToString());
            }
            reader->Close();
            conn->Close();
        }

        void AvailableSectionIDcb()
        {
			String^ connetionString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
            SqlConnection^ conn = gcnew SqlConnection(connetionString);
            conn->Open();
            SqlCommand^ cmd = gcnew SqlCommand("SELECT SectionID FROM Sections", conn);
            SqlDataReader^ reader = cmd->ExecuteReader();
            while (reader->Read())
            {
                SectionIDcb->Items->Add(reader["SectionID"]->ToString());
            }
            reader->Close();
            conn->Close();
        }

        System::Void timetable_Load(System::Object^ sender, System::EventArgs^ e){
         
        }

        System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e){


            if (String::IsNullOrEmpty(TeacherIDcb->Text) || String::IsNullOrEmpty(RoomIDcb->Text) || String::IsNullOrEmpty(StartTimecb->Text) || String::IsNullOrEmpty(SectionIDcb->Text) || String::IsNullOrEmpty(Daycb->Text)) {
                MessageBox::Show(" Please fill in all fields to Continue. ");
                return;
            }
            if (TeacherIDcb->SelectedIndex == -1 || RoomIDcb->SelectedIndex == -1 || CourseIDcb->SelectedIndex == -1 || SectionIDcb->SelectedIndex == -1 || Daycb->SelectedIndex == -1 || StartTimecb->SelectedIndex == -1)
            {
                MessageBox::Show("Please fill all the fields before saving.");
                return;
            }

            String^ teacherID = TeacherIDcb->SelectedItem->ToString();
            String^ roomID = RoomIDcb->SelectedItem->ToString();
            String^ courseID = CourseIDcb->SelectedItem->ToString();
            String^ sectionID = SectionIDcb->SelectedItem->ToString();
            String^ day = Daycb->SelectedItem->ToString();
            String^ startTime = StartTimecb->SelectedItem->ToString();

            SqlConnection^ conn = nullptr;

            try
            {
                String^ connectionString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
                conn = gcnew SqlConnection(connectionString);
                conn->Open();

                String^ section = (sectionID == "1") ? "BSE-2A" : "BSE-2B";
                // Check for existing slots
                String^ checkQuery = "SELECT COUNT(*) FROM [" + section + "] WHERE Day = @Day AND StartTime = @StartTime";
				/*String^ checkQuery = "SELECT COUNT(*) FROM [BSE-2A] UNION [BSE-2B] WHERE Day = @Day AND StartTime = @StartTime";*/
                SqlCommand^ checkCmd = gcnew SqlCommand(checkQuery, conn);
                checkCmd->Parameters->AddWithValue("@Day", day);
                checkCmd->Parameters->AddWithValue("@StartTime", startTime);

                int count = (int)checkCmd->ExecuteScalar();
                if (count > 0) {

                    MessageBox::Show("This slot is already scheduled at this time and day.");
                }
                else {

                    String^ query = "INSERT INTO [" + section + "] (CourseID, RoomID, TeacherID, StartTime, Day) VALUES (@CourseID, @RoomID, @TeacherID, @StartTime, @Day)";

                    // Debugging statement to print the query
                    MessageBox::Show("Executing query: " + query);

                    SqlCommand^ cmd = gcnew SqlCommand(query, conn);
                    cmd->Parameters->AddWithValue("@CourseID", courseID);
                    cmd->Parameters->AddWithValue("@RoomID", roomID);
                    cmd->Parameters->AddWithValue("@TeacherID", teacherID);
                    cmd->Parameters->AddWithValue("@StartTime", startTime);
                    cmd->Parameters->AddWithValue("@Day", day);

                    cmd->ExecuteNonQuery();
                    MessageBox::Show("Timetable slot saved successfully.");
                }
            }
            catch (Exception^ ex_s)
            {
                MessageBox::Show("An error occurred while saving the timetable slot: " + ex_s->Message);
            }
            catch (SqlException^ ex_sql) {
				MessageBox::Show("Error Occured while saving the timetable slot: " + ex_sql->Message);
            }
            finally
            {
                if (conn != nullptr)
                {
                    conn->Close();
                }
            }
        }

        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->Hide();
            dash->Show();
        }

        System::Void SectionIDcb_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
        {
            
        }
    };
}
