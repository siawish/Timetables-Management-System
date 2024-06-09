#pragma once

namespace TimeTableGenerator {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;

    public ref class SearchByCourse : public System::Windows::Forms::Form
    {
    private:
        System::Windows::Forms::Form^ dash;
    public:
        SearchByCourse(void)
        {
            InitializeComponent();
        }

        SearchByCourse(System::Windows::Forms::Form^ obj)
        {
            InitializeComponent();
            dash = obj;
        }

    protected:
        ~SearchByCourse()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::Button^ searchByCourseButton;
    private: System::Windows::Forms::ComboBox^ Coursecb;
    private: System::Windows::Forms::Button^ button1;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->searchByCourseButton = (gcnew System::Windows::Forms::Button());
            this->Coursecb = (gcnew System::Windows::Forms::ComboBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(91, 95);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(73, 16);
            this->label2->TabIndex = 9;
            this->label2->Text = L"Course ID :";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(438, 35);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(247, 32);
            this->label1->TabIndex = 8;
            this->label1->Text = L"Search By Course";
            // 
            // dataGridView1
            // 
            this->dataGridView1->AllowUserToAddRows = false;
            this->dataGridView1->AllowUserToDeleteRows = false;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(38, 164);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->ReadOnly = true;
            this->dataGridView1->RowHeadersVisible = false;
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->RowTemplate->Height = 24;
            this->dataGridView1->Size = System::Drawing::Size(996, 367);
            this->dataGridView1->TabIndex = 7;
            // 
            // searchByCourseButton
            // 
            this->searchByCourseButton->Location = System::Drawing::Point(535, 122);
            this->searchByCourseButton->Name = L"searchByCourseButton";
            this->searchByCourseButton->Size = System::Drawing::Size(122, 27);
            this->searchByCourseButton->TabIndex = 6;
            this->searchByCourseButton->Text = L"Search";
            this->searchByCourseButton->UseVisualStyleBackColor = true;
            this->searchByCourseButton->Click += gcnew System::EventHandler(this, &SearchByCourse::searchByCourseButton_Click);
            // 
            // Coursecb
            // 
            this->Coursecb->FormattingEnabled = true;
            this->Coursecb->Location = System::Drawing::Point(91, 125);
            this->Coursecb->Name = L"Coursecb";
            this->Coursecb->Size = System::Drawing::Size(400, 24);
            this->Coursecb->TabIndex = 5;
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(676, 121);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(122, 27);
            this->button1->TabIndex = 10;
            this->button1->Text = L"Back";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &SearchByCourse::button1_Click);
            // 
            // SearchByCourse
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1123, 534);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->searchByCourseButton);
            this->Controls->Add(this->Coursecb);
            this->Name = L"SearchByCourse";
            this->Text = L"SearchByCourse";
            this->Load += gcnew System::EventHandler(this, &SearchByCourse::SearchByCourse_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void searchByCourseButton_Click(System::Object^ sender, System::EventArgs^ e) {
        try
        {
            if (Coursecb->SelectedItem == nullptr)
            {
                MessageBox::Show("Please select a Course ID.");
                return;
            }

            String^ connString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
            SqlConnection^ conn = gcnew SqlConnection(connString);
            String^ CourseID = Coursecb->SelectedItem->ToString()->Split('-')[0]->Trim();
            String^ query = "SELECT * FROM [BSE-2A] WHERE CourseID = @CourseID UNION SELECT * FROM [BSE-2B] WHERE CourseID = @CourseID";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@CourseID", CourseID);

            SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
            DataTable^ dt = gcnew DataTable();
            da->Fill(dt);
            dataGridView1->DataSource = dt;
        }
        catch (Exception^ ex)
        {
            MessageBox::Show(ex->Message);
        }
    }

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
        dash->Show();
    }

    private: System::Void SearchByCourse_Load(System::Object^ sender, System::EventArgs^ e) {
        // Populate Coursecb with course data from the database
        String^ connString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
        SqlConnection^ conn = gcnew SqlConnection(connString);

        try {
            conn->Open();
            String^ query = "SELECT CourseID, CourseName FROM Course";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);
            SqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                String^ courseID = reader["CourseID"]->ToString();
                String^ courseName = reader["CourseName"]->ToString();
                // Add courseID and courseName to the ComboBox
                Coursecb->Items->Add(courseID + " - " + courseName);
            }
            reader->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error occurred: " + ex->Message);
        }
        finally {
            conn->Close();
        }
    }

    };
}
