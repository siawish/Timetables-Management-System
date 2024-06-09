#pragma once






namespace TimeTableGenerator {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;

    /// <summary>
    /// Summary for SearchBYSection
    /// </summary>
    public ref class SearchBYSection : public System::Windows::Forms::Form
    {
    private:
        System::Windows::Forms::Form^ dash;
    private:
        System::Windows::Forms::Form^ tdash;

    public:
       SearchBYSection(void)
        {
            InitializeComponent();
            AvailableSectionIDcb();
        }

		SearchBYSection(Form^  obj)
		{

			InitializeComponent();
			AvailableSectionIDcb();
           
            dash = obj;
			tdash = obj;
		}

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~SearchBYSection()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::ComboBox^ Sectioncb;
        System::Windows::Forms::Button^ searchBySectionButton;
        System::Windows::Forms::DataGridView^ dataGridView1;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Button^ button1;
           System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->Sectioncb = (gcnew System::Windows::Forms::ComboBox());
            this->searchBySectionButton = (gcnew System::Windows::Forms::Button());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // Sectioncb
            // 
            this->Sectioncb->FormattingEnabled = true;
            this->Sectioncb->Location = System::Drawing::Point(36, 90);
            this->Sectioncb->Name = L"Sectioncb";
            this->Sectioncb->Size = System::Drawing::Size(200, 24);
            this->Sectioncb->TabIndex = 0;
            this->Sectioncb->SelectedIndexChanged += gcnew System::EventHandler(this, &SearchBYSection::Sectioncb_SelectedIndexChanged);
            // 
            // searchBySectionButton
            // 
            this->searchBySectionButton->Location = System::Drawing::Point(257, 88);
            this->searchBySectionButton->Name = L"searchBySectionButton";
            this->searchBySectionButton->Size = System::Drawing::Size(122, 27);
            this->searchBySectionButton->TabIndex = 1;
            this->searchBySectionButton->Text = L"Search";
            this->searchBySectionButton->UseVisualStyleBackColor = true;
            this->searchBySectionButton->Click += gcnew System::EventHandler(this, &SearchBYSection::searchBySectionButton_Click);
            // 
            // dataGridView1
            // 
            this->dataGridView1->AllowUserToAddRows = false;
            this->dataGridView1->AllowUserToDeleteRows = false;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(36, 140);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->ReadOnly = true;
            this->dataGridView1->RowHeadersVisible = false;
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->RowTemplate->Height = 24;
            this->dataGridView1->Size = System::Drawing::Size(996, 367);
            this->dataGridView1->TabIndex = 2;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(406, 30);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(264, 32);
            this->label1->TabIndex = 3;
            this->label1->Text = L"Search By Section";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(36, 60);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(71, 16);
            this->label2->TabIndex = 4;
            this->label2->Text = L"Section ID:";
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(408, 88);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(122, 27);
            this->button1->TabIndex = 5;
            this->button1->Text = L"Back";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &SearchBYSection::button1_Click);
            // 
            // SearchBYSection
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1068, 556);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->searchBySectionButton);
            this->Controls->Add(this->Sectioncb);
            this->Name = L"SearchBYSection";
            this->Text = L"SearchBYSection";
            this->Load += gcnew System::EventHandler(this, &SearchBYSection::SearchBYSection_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        void AvailableSectionIDcb()
        {
            try
            {
                String^ connString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
                SqlConnection^ conn = gcnew SqlConnection(connString);
                String^ query = "SELECT SectionName FROM Sections";
                SqlCommand^ cmd = gcnew SqlCommand(query, conn);
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read())
                {
                    Sectioncb->Items->Add(reader["SectionName"]->ToString());
                }
                reader->Close();
                conn->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show(ex->Message);
            }
        }

    private: System::Void SearchBYSection_Load(System::Object^ sender, System::EventArgs^ e)
    {
        dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;  dataGridView1->MultiSelect = false;
    }

    private: System::Void searchBySectionButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (Sectioncb->SelectedItem == nullptr)
        {
            MessageBox::Show("Please select a section.");
            return;
        }

        String^ sectionTable = Sectioncb->SelectedItem->ToString();
      

        String^ connString = "Data Source=CYBER-S4A9I7H;Initial Catalog=TimeTable;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
        SqlConnection^ conn = gcnew SqlConnection(connString);

        try {
            conn->Open();

            String^ query = "SELECT (*) FROM [" + sectionTable+"]";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            SqlDataAdapter^ adapter = gcnew SqlDataAdapter(cmd);
            DataTable^ dt = gcnew DataTable();
            adapter->Fill(dt);

            dataGridView1->DataSource = dt;
        }
        catch (Exception^ ex) {
            MessageBox::Show(" An Error occurred: " + ex->Message);
        }
        finally {
            conn->Close();
        }
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
        dash->Show();

       

        // Depending Upon the UserType back button Works 
       // this->Hide();
   //     if (Login::usertype == "Teacher") {
			//Teacherdash->Show();//returning back to teacher dashboard

   //     }
   //     else if (Login::usertype == "Admin") {
        //try {
          //  dash->Show();//returning back to admin dashboard
        //}
        //catch (Exception^ ex) {
			//tdash->Show();//returning back to admin dashboard with  
        //}
   //     }
   //     else
			//studentdash->Show();//returning back to student dashboard
    
    }
private: System::Void Sectioncb_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}