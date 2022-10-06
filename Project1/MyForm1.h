#pragma once

namespace Project1
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	using namespace System::Collections::Generic;
	
	using namespace System::Text;
	using namespace System::Runtime::InteropServices;



	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			
			this->Working_area->Size = System::Drawing::Size(10000, 10000);
			this->Working_area->Location = System::Drawing::Point(-5000, -5000);

			dataGridView1->Rows->Add();
			dataGridView1->Rows[0]->Cells[0]->Value = "aaaaaaaaaaa";
			dataGridView1->Rows->Add();
			dataGridView1->Rows[1]->Cells[0]->Value = "bbbbbbbbbb";
			dataGridView1->Rows->Add();
			dataGridView1->Rows[2]->Cells[0]->Value = "ccccccccc";

			setNewReg(button_Exit, 8);
			setNewReg(button_minimise, 8);
			setNewReg(button_roll, 8);

			this->Controls->Add(this->Working_area);

			this->Working_area->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &Project1::MyForm::OnMouseWheel);

			//this->Working_area->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Project1::MyForm::OnKeyDown);

			//this->Working_area->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &Project1::MyForm::Working_area_MouseWheel);

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
	private:

		Point MouseDownLocation;																	//Координаты мыши в момент зажатия лкм.

		Object^ CurrentObj;																			//Выбранный объект.
		int NomberObj;																				//Номер выбранного объекта.
		int NomberContact;																			//Номер объекта, с которым произошло столкновение.

		int countObj = 0;																			//Колличество объектов на поле.
		int Experiment = 0;																			//Счётчик перемещений.

		int CentralObjX = 0, CentralObjY = 0;														//Координаты центра объектов.
		int CentralObjX2 = 0, CentralObjY2 = 0;

		int DeltaX = 0;
		int DeltaY = 0;

		int dx = 0;																					//Смещение объекта при перемещении по оси Х за шаг.
		int dy = 0;																					//Смещение объекта при перемещении по оси У за шаг.

		int margin = 15;																			//Промежуток между полями объектов.

		//float IndScale = 1;																			//Коэфициент увеличения.

		float ScaleFont = 10.28571F;																//Размер шрифта.

		int NormalHeightObject = 32 + 7 * 2 * 10.28571F;											//Стоковая высота объекта.
		int NormalWidthObject = 130;																//Стоковая ширина объекта.

		bool Flag = false;
		bool AllObjLocked = false;																	//Все объекты заблокированы?

		bool Touch_Left_Border = false;																//Касание Левой грани Соприкасаемого Объекта.
		bool Touch_Right_Border = false;															//Касание Правой грани Соприкасаемого Объекта.
		bool Touch_Top_Border = false;																//Касание Верхней грани Соприкасаемого Объекта.
		bool Touch_Down_Border = false;																//Касание Нижней грани Соприкасаемого Объекта.

		bool BorderLeft = false;																	//Была ли Левая грань пересечана?
		bool BorderRight = false;																	//Была ли Правая грань пересечана?
		bool BorderTop = false;																		//Была ли Верхняя грань пересечана?
		bool BorderDown = false;																	//Была ли Нижняя грань пересечана?

		bool FullScreen = false;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;



		TextBox^ RenameTextBox;


		template <class T> 
		void setNewReg(T^, int);

//-------------------------------------------------------------------------------
//===============================================================================
//-------------------------------------------------------------------------------

		//Массивы:
		cli::array<Panel^>^ MassPanel;
		cli::array<Label^>^ MassNameFactory;
		cli::array<ListBox^>^ MassListBox;
		cli::array<TextBox^>^ MassTextBox;

		cli::array<bool^>^ MassObjLocked;

		//Буфферные массивы:
		cli::array<Panel^>^ BufferMassPanel;
		cli::array<Label^>^ BufferMassNameFactory;
		cli::array<ListBox^>^ BufferMassListBox;
		cli::array<TextBox^>^ BufferMassTextBox;

		cli::array<bool^>^ BufferMassObjLocked;



//-------------------------------------------------------------------------------
//===============================================================================
//-------------------------------------------------------------------------------

		System::Windows::Forms::ContextMenuStrip^ menu_Object;

		ToolStripMenuItem^ Menu_RenameObject;
		ToolStripMenuItem^ menu_DelRes;
		ToolStripMenuItem^ Menu_fixObject;
		ToolStripMenuItem^ menu_DelObj;
		ToolStripMenuItem^ menu_addRes;
		ToolStripMenuItem^ menu_addDelivery;
		ToolStripMenuItem^ menu_DelDelivery;

		ToolStripSeparator^ toolStripSeparator1;
		ToolStripSeparator^ toolStripSeparator2;
		ToolStripSeparator^ toolStripSeparator3;
		ToolStripSeparator^ toolStripSeparator4;

//-------------------------------------------------------------------------------
//===============================================================================
//-------------------------------------------------------------------------------

		System::Windows::Forms::ContextMenuStrip^ menu_Res;

		ToolStripMenuItem^ res_Rename;
		ToolStripMenuItem^ res_addDlvr;
		ToolStripMenuItem^ resdelResToolStripMenuItem;
		ToolStripMenuItem^ resdelDlvrToolStripMenuItem;

		ToolStripSeparator^ toolStripSeparator5;
		ToolStripSeparator^ toolStripSeparator6;

//-------------------------------------------------------------------------------
//===============================================================================
//-------------------------------------------------------------------------------

		MenuStrip^ Hat_menu;

		ToolStripMenuItem^ Hat_menuItem_File;
		ToolStripMenuItem^ Hat_menuItem_Style;
		ToolStripMenuItem^ Hat_menuItem_Info;

//-------------------------------------------------------------------------------
//===============================================================================
//-------------------------------------------------------------------------------

		Windows::Forms::Panel^ Exp_panel;
		Windows::Forms::Label^ Exp_NameFactory;
		Windows::Forms::ListBox^ Exp_listBox;

//-------------------------------------------------------------------------------
//===============================================================================
//-------------------------------------------------------------------------------

		System::Windows::Forms::ContextMenuStrip^ menu_Area;

		ToolStripMenuItem^ MenuPlane_addFactory;
		ToolStripMenuItem^ MenuPlane_fixAllObj;

//-------------------------------------------------------------------------------
//===============================================================================
//-------------------------------------------------------------------------------

		Panel^ Hat;
		Button^ button_minimise;
	    Button^ button_Exit;
	    Button^ ScaleWindow;
	    Button^ button_roll;

//-------------------------------------------------------------------------------
//===============================================================================
//-------------------------------------------------------------------------------

		Panel^ Working_area;

//-------------------------------------------------------------------------------
//===============================================================================
//-------------------------------------------------------------------------------

		TextBox^ textBox1;
		TextBox^ textBox2;
		TextBox^ textBox3;

//-------------------------------------------------------------------------------

		IContainer^ components;

//-------------------------------------------------------------------------------

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menu_Object = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->Menu_RenameObject = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->menu_addRes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_addDelivery = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->menu_DelRes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_DelObj = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_DelDelivery = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->Menu_fixObject = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Hat_menu = (gcnew System::Windows::Forms::MenuStrip());
			this->Hat_menuItem_File = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Hat_menuItem_Style = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Hat_menuItem_Info = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Exp_panel = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menu_Res = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->res_Rename = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->res_addDlvr = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->resdelResToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resdelDlvrToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->Exp_NameFactory = (gcnew System::Windows::Forms::Label());
			this->Exp_listBox = (gcnew System::Windows::Forms::ListBox());
			this->menu_Area = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->MenuPlane_addFactory = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->MenuPlane_fixAllObj = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Hat = (gcnew System::Windows::Forms::Panel());
			this->button_roll = (gcnew System::Windows::Forms::Button());
			this->button_Exit = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button_minimise = (gcnew System::Windows::Forms::Button());
			this->Working_area = (gcnew System::Windows::Forms::Panel());
			this->ScaleWindow = (gcnew System::Windows::Forms::Button());
			this->menu_Object->SuspendLayout();
			this->Hat_menu->SuspendLayout();
			this->Exp_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menu_Res->SuspendLayout();
			this->menu_Area->SuspendLayout();
			this->Hat->SuspendLayout();
			this->SuspendLayout();
			// 
			// menu_Object
			// 
			this->menu_Object->ImageScalingSize = System::Drawing::Size(18, 18);
			this->menu_Object->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
				this->Menu_RenameObject,
					this->toolStripSeparator2, this->menu_addRes, this->menu_addDelivery, this->toolStripSeparator3, this->menu_DelRes, this->menu_DelObj,
					this->menu_DelDelivery, this->toolStripSeparator1, this->Menu_fixObject
			});
			this->menu_Object->Name = L"contextMenuStrip1";
			this->menu_Object->ShowImageMargin = false;
			this->menu_Object->Size = System::Drawing::Size(189, 176);
			// 
			// Menu_RenameObject
			// 
			this->Menu_RenameObject->Name = L"Menu_RenameObject";
			this->Menu_RenameObject->Size = System::Drawing::Size(188, 22);
			this->Menu_RenameObject->Text = L"Переименовать";
			this->Menu_RenameObject->Click += gcnew System::EventHandler(this, &MyForm::Menu_RenameObject_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(185, 6);
			// 
			// menu_addRes
			// 
			this->menu_addRes->Name = L"menu_addRes";
			this->menu_addRes->Size = System::Drawing::Size(188, 22);
			this->menu_addRes->Text = L"Добавить ресурс";
			// 
			// menu_addDelivery
			// 
			this->menu_addDelivery->Name = L"menu_addDelivery";
			this->menu_addDelivery->Size = System::Drawing::Size(188, 22);
			this->menu_addDelivery->Text = L"Добавить поставку";
			this->menu_addDelivery->Click += gcnew System::EventHandler(this, &MyForm::menu_addDelivery_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(185, 6);
			// 
			// menu_DelRes
			// 
			this->menu_DelRes->Name = L"menu_DelRes";
			this->menu_DelRes->Size = System::Drawing::Size(188, 22);
			this->menu_DelRes->Text = L"Удалить ресурс";
			// 
			// menu_DelObj
			// 
			this->menu_DelObj->Name = L"menu_DelObj";
			this->menu_DelObj->Size = System::Drawing::Size(188, 22);
			this->menu_DelObj->Text = L"Удалить объект";
			this->menu_DelObj->Click += gcnew System::EventHandler(this, &MyForm::dellObjectToolStripMenuItem_Click);
			// 
			// menu_DelDelivery
			// 
			this->menu_DelDelivery->Name = L"menu_DelDelivery";
			this->menu_DelDelivery->Size = System::Drawing::Size(188, 22);
			this->menu_DelDelivery->Text = L"Удалить поставку";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(185, 6);
			// 
			// Menu_fixObject
			// 
			this->Menu_fixObject->Name = L"Menu_fixObject";
			this->Menu_fixObject->Size = System::Drawing::Size(188, 22);
			this->Menu_fixObject->Text = L"Зафиксировать объект";
			this->Menu_fixObject->Click += gcnew System::EventHandler(this, &MyForm::Menu_fixObject_Click);
			// 
			// Hat_menu
			// 
			this->Hat_menu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->Hat_menu->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->Hat_menu->ImageScalingSize = System::Drawing::Size(18, 18);
			this->Hat_menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->Hat_menuItem_File,
					this->Hat_menuItem_Style, this->Hat_menuItem_Info
			});
			this->Hat_menu->Location = System::Drawing::Point(0, 25);
			this->Hat_menu->Name = L"Hat_menu";
			this->Hat_menu->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->Hat_menu->Size = System::Drawing::Size(818, 24);
			this->Hat_menu->TabIndex = 1;
			this->Hat_menu->Text = L"menuStrip1";
			// 
			// Hat_menuItem_File
			// 
			this->Hat_menuItem_File->Font = (gcnew System::Drawing::Font(L"Consolas", 8.914286F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Hat_menuItem_File->ForeColor = System::Drawing::SystemColors::Control;
			this->Hat_menuItem_File->Name = L"Hat_menuItem_File";
			this->Hat_menuItem_File->Size = System::Drawing::Size(47, 20);
			this->Hat_menuItem_File->Text = L"Файл";
			// 
			// Hat_menuItem_Style
			// 
			this->Hat_menuItem_Style->Font = (gcnew System::Drawing::Font(L"Consolas", 8.914286F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Hat_menuItem_Style->ForeColor = System::Drawing::SystemColors::Control;
			this->Hat_menuItem_Style->Name = L"Hat_menuItem_Style";
			this->Hat_menuItem_Style->Size = System::Drawing::Size(54, 20);
			this->Hat_menuItem_Style->Text = L"Стиль";
			// 
			// Hat_menuItem_Info
			// 
			this->Hat_menuItem_Info->Font = (gcnew System::Drawing::Font(L"Consolas", 8.914286F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Hat_menuItem_Info->ForeColor = System::Drawing::SystemColors::Control;
			this->Hat_menuItem_Info->Name = L"Hat_menuItem_Info";
			this->Hat_menuItem_Info->Size = System::Drawing::Size(68, 20);
			this->Hat_menuItem_Info->Text = L"Справка";
			// 
			// Exp_panel
			// 
			this->Exp_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Exp_panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->Exp_panel->ContextMenuStrip = this->menu_Object;
			this->Exp_panel->Controls->Add(this->dataGridView1);
			this->Exp_panel->Controls->Add(this->textBox3);
			this->Exp_panel->Controls->Add(this->Exp_NameFactory);
			this->Exp_panel->Controls->Add(this->Exp_listBox);
			this->Exp_panel->Location = System::Drawing::Point(30, 60);
			this->Exp_panel->Margin = System::Windows::Forms::Padding(30);
			this->Exp_panel->MinimumSize = System::Drawing::Size(65, 0);
			this->Exp_panel->Name = L"Exp_panel";
			this->Exp_panel->Padding = System::Windows::Forms::Padding(2, 0, 0, 0);
			this->Exp_panel->Size = System::Drawing::Size(252, 182);
			this->Exp_panel->TabIndex = 0;
			this->Exp_panel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Object_MouseDown);
			this->Exp_panel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Object_MousMove);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleRight;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.542857F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)));
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Column1 });
			this->dataGridView1->ContextMenuStrip = this->menu_Res;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)), static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.542857F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::Desktop;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::ButtonShadow;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->dataGridView1->Location = System::Drawing::Point(83, 36);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->dataGridView1->RowTemplate->DividerHeight = 5;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(111, 126);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->RowHeaderMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MyForm::dataGridView1_RowHeaderMouseClick);
			this->dataGridView1->RowHeaderMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MyForm::ShowDelivery);
			// 
			// Column1
			// 
			this->Column1->ContextMenuStrip = this->menu_Res;
			this->Column1->HeaderText = L"Resources";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 109;
			// 
			// menu_Res
			// 
			this->menu_Res->ImageScalingSize = System::Drawing::Size(18, 18);
			this->menu_Res->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->res_Rename, this->toolStripSeparator6,
					this->res_addDlvr, this->toolStripSeparator5, this->resdelResToolStripMenuItem, this->resdelDlvrToolStripMenuItem
			});
			this->menu_Res->Name = L"contextMenuStrip1";
			this->menu_Res->Size = System::Drawing::Size(191, 104);
			// 
			// res_Rename
			// 
			this->res_Rename->Name = L"res_Rename";
			this->res_Rename->Size = System::Drawing::Size(190, 22);
			this->res_Rename->Text = L"Переименовать";
			// 
			// toolStripSeparator6
			// 
			this->toolStripSeparator6->Name = L"toolStripSeparator6";
			this->toolStripSeparator6->Size = System::Drawing::Size(187, 6);
			// 
			// res_addDlvr
			// 
			this->res_addDlvr->Name = L"res_addDlvr";
			this->res_addDlvr->Size = System::Drawing::Size(190, 22);
			this->res_addDlvr->Text = L"Добавить поставку";
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(187, 6);
			// 
			// resdelResToolStripMenuItem
			// 
			this->resdelResToolStripMenuItem->Name = L"resdelResToolStripMenuItem";
			this->resdelResToolStripMenuItem->Size = System::Drawing::Size(190, 22);
			this->resdelResToolStripMenuItem->Text = L"Удалить ресурс";
			// 
			// resdelDlvrToolStripMenuItem
			// 
			this->resdelDlvrToolStripMenuItem->Name = L"resdelDlvrToolStripMenuItem";
			this->resdelDlvrToolStripMenuItem->Size = System::Drawing::Size(190, 22);
			this->resdelDlvrToolStripMenuItem->Text = L"Удалить поставку";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(182, 10);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 1;
			// 
			// Exp_NameFactory
			// 
			this->Exp_NameFactory->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Exp_NameFactory->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Exp_NameFactory->ContextMenuStrip = this->menu_Object;
			this->Exp_NameFactory->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->Exp_NameFactory->Font = (gcnew System::Drawing::Font(L"Consolas", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Exp_NameFactory->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->Exp_NameFactory->Location = System::Drawing::Point(4, 10);
			this->Exp_NameFactory->MinimumSize = System::Drawing::Size(70, 15);
			this->Exp_NameFactory->Name = L"Exp_NameFactory";
			this->Exp_NameFactory->Size = System::Drawing::Size(248, 29);
			this->Exp_NameFactory->TabIndex = 0;
			this->Exp_NameFactory->Text = L"Фабрика";
			this->Exp_NameFactory->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Exp_listBox
			// 
			this->Exp_listBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->Exp_listBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Exp_listBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Exp_listBox->ColumnWidth = 2;
			this->Exp_listBox->ContextMenuStrip = this->menu_Res;
			this->Exp_listBox->Font = (gcnew System::Drawing::Font(L"Consolas", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Exp_listBox->ForeColor = System::Drawing::SystemColors::MenuBar;
			this->Exp_listBox->FormattingEnabled = true;
			this->Exp_listBox->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Exp_listBox->ItemHeight = 18;
			this->Exp_listBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"abc1", L"dfd4", L"fsaf2", L"sdf", L"ssss",
					L"ssss1", L"ssss2"
			});
			this->Exp_listBox->Location = System::Drawing::Point(7, 42);
			this->Exp_listBox->MinimumSize = System::Drawing::Size(70, 18);
			this->Exp_listBox->Name = L"Exp_listBox";
			this->Exp_listBox->Size = System::Drawing::Size(70, 126);
			this->Exp_listBox->Sorted = true;
			this->Exp_listBox->TabIndex = 0;
			// 
			// menu_Area
			// 
			this->menu_Area->ImageScalingSize = System::Drawing::Size(18, 18);
			this->menu_Area->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->MenuPlane_addFactory,
					this->toolStripSeparator4, this->MenuPlane_fixAllObj
			});
			this->menu_Area->Name = L"contextMenuPlane";
			this->menu_Area->ShowImageMargin = false;
			this->menu_Area->Size = System::Drawing::Size(222, 54);
			// 
			// MenuPlane_addFactory
			// 
			this->MenuPlane_addFactory->Name = L"MenuPlane_addFactory";
			this->MenuPlane_addFactory->Size = System::Drawing::Size(221, 22);
			this->MenuPlane_addFactory->Text = L"Добавить завод";
			this->MenuPlane_addFactory->Click += gcnew System::EventHandler(this, &MyForm::addFactoryToolStripMenuItem_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(218, 6);
			// 
			// MenuPlane_fixAllObj
			// 
			this->MenuPlane_fixAllObj->Name = L"MenuPlane_fixAllObj";
			this->MenuPlane_fixAllObj->Size = System::Drawing::Size(221, 22);
			this->MenuPlane_fixAllObj->Text = L"Зафиксировать все объекты";
			this->MenuPlane_fixAllObj->Click += gcnew System::EventHandler(this, &MyForm::MenuPlane_fixAllObj_Click);
			// 
			// Hat
			// 
			this->Hat->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(41)));
			this->Hat->Controls->Add(this->button_roll);
			this->Hat->Controls->Add(this->button_Exit);
			this->Hat->Controls->Add(this->textBox2);
			this->Hat->Controls->Add(this->textBox1);
			this->Hat->Controls->Add(this->button_minimise);
			this->Hat->Controls->Add(this->Hat_menu);
			this->Hat->Dock = System::Windows::Forms::DockStyle::Top;
			this->Hat->Location = System::Drawing::Point(0, 0);
			this->Hat->Name = L"Hat";
			this->Hat->Size = System::Drawing::Size(818, 49);
			this->Hat->TabIndex = 1;
			this->Hat->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Hat_MouseDown);
			this->Hat->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Hat_MousMove);
			// 
			// button_roll
			// 
			this->button_roll->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button_roll->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button_roll->FlatAppearance->BorderSize = 0;
			this->button_roll->FlatAppearance->MouseOverBackColor = System::Drawing::Color::CornflowerBlue;
			this->button_roll->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_roll->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->button_roll->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_roll.Image")));
			this->button_roll->Location = System::Drawing::Point(672, 0);
			this->button_roll->Name = L"button_roll";
			this->button_roll->Size = System::Drawing::Size(45, 25);
			this->button_roll->TabIndex = 6;
			this->button_roll->UseVisualStyleBackColor = true;
			this->button_roll->Click += gcnew System::EventHandler(this, &MyForm::button_roll_Click);
			// 
			// button_Exit
			// 
			this->button_Exit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button_Exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(41)));
			this->button_Exit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button_Exit->FlatAppearance->BorderSize = 0;
			this->button_Exit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button_Exit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Salmon;
			this->button_Exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Exit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->button_Exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Exit.Image")));
			this->button_Exit->Location = System::Drawing::Point(774, 0);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(45, 25);
			this->button_Exit->TabIndex = 5;
			this->button_Exit->UseVisualStyleBackColor = false;
			this->button_Exit->Click += gcnew System::EventHandler(this, &MyForm::button_Exit_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(539, 26);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(267, 20);
			this->textBox2->TabIndex = 4;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(190, 26);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(343, 20);
			this->textBox1->TabIndex = 3;
			// 
			// button_minimise
			// 
			this->button_minimise->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button_minimise->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(41)));
			this->button_minimise->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button_minimise->FlatAppearance->BorderSize = 0;
			this->button_minimise->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button_minimise->FlatAppearance->MouseOverBackColor = System::Drawing::Color::CornflowerBlue;
			this->button_minimise->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_minimise->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->button_minimise->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_minimise.Image")));
			this->button_minimise->Location = System::Drawing::Point(723, 0);
			this->button_minimise->Name = L"button_minimise";
			this->button_minimise->Size = System::Drawing::Size(45, 25);
			this->button_minimise->TabIndex = 2;
			this->button_minimise->UseVisualStyleBackColor = false;
			this->button_minimise->Click += gcnew System::EventHandler(this, &MyForm::button_minimise_Click);
			// 
			// Working_area
			// 
			this->Working_area->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->Working_area->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Working_area->ContextMenuStrip = this->menu_Area;
			this->Working_area->Location = System::Drawing::Point(581, 70);
			this->Working_area->Name = L"Working_area";
			this->Working_area->Size = System::Drawing::Size(202, 206);
			this->Working_area->TabIndex = 3;
			this->Working_area->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Working_area_MouseDown);
			this->Working_area->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::WorkingArea_MouseMove);
			this->Working_area->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Working_area_MouseUp);
			// 
			// ScaleWindow
			// 
			this->ScaleWindow->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->ScaleWindow->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ScaleWindow->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ScaleWindow->Cursor = System::Windows::Forms::Cursors::SizeAll;
			this->ScaleWindow->FlatAppearance->BorderSize = 0;
			this->ScaleWindow->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ScaleWindow->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ScaleWindow->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ScaleWindow->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ScaleWindow->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ScaleWindow.Image")));
			this->ScaleWindow->Location = System::Drawing::Point(798, 492);
			this->ScaleWindow->Margin = System::Windows::Forms::Padding(0);
			this->ScaleWindow->Name = L"ScaleWindow";
			this->ScaleWindow->Size = System::Drawing::Size(21, 21);
			this->ScaleWindow->TabIndex = 4;
			this->ScaleWindow->UseVisualStyleBackColor = false;
			this->ScaleWindow->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::ScaleWindow_MouseMove);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->ClientSize = System::Drawing::Size(818, 513);
			this->Controls->Add(this->ScaleWindow);
			this->Controls->Add(this->Working_area);
			this->Controls->Add(this->Hat);
			this->Controls->Add(this->Exp_panel);
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::SystemColors::Desktop;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menu_Object->ResumeLayout(false);
			this->Hat_menu->ResumeLayout(false);
			this->Hat_menu->PerformLayout();
			this->Exp_panel->ResumeLayout(false);
			this->Exp_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menu_Res->ResumeLayout(false);
			this->menu_Area->ResumeLayout(false);
			this->Hat->ResumeLayout(false);
			this->Hat->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:

//==========================================================================================================================

		//Измененная форма окна программы:
		System::Void MyForm_Load(Object^ sender, EventArgs^ e)
		{
			
		}

//==========================================================================================================================

		//Функция добавление новых объектов на плоскость.
		System::Void addFactoryToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
		{

			//Если объектов на поле не 0:
			if (countObj != 0)
			{
				//Сохранить значения основных массивов в буферные:
				BufferMassPanel = MassPanel;
				BufferMassNameFactory = MassNameFactory;
				BufferMassListBox = MassListBox;
				BufferMassTextBox = MassTextBox;

				BufferMassObjLocked = MassObjLocked;

				//Выделить память для новых массивов на единицу больше:
				MassPanel = gcnew array<System::Windows::Forms::Panel^>(countObj + 1);
				MassNameFactory = gcnew array<System::Windows::Forms::Label^>(countObj + 1);
				MassListBox = gcnew array<System::Windows::Forms::ListBox^>(countObj + 1);
				MassTextBox = gcnew array<System::Windows::Forms::TextBox^>(countObj + 1);

				MassObjLocked = gcnew array<bool^>(countObj + 1);

				//Сохранить значения старого массива в новый:
				for (int i = 0; i < countObj; i++)
				{
					MassPanel[i] = BufferMassPanel[i];
					MassNameFactory[i] = BufferMassNameFactory[i];
					MassListBox[i] = BufferMassListBox[i];
					MassTextBox[i] = BufferMassTextBox[i];

					MassObjLocked[i] = BufferMassObjLocked[i];
				}

				InicialNewObject(countObj);

				//Увеличить число объектов на поле.
				countObj++;
			}
			//Если объектов на поле 0:
			else
			{
				MassPanel = gcnew array<System::Windows::Forms::Panel^>(countObj + 1);
				MassNameFactory = gcnew array<System::Windows::Forms::Label^>(countObj + 1);
				MassListBox = gcnew array<System::Windows::Forms::ListBox^>(countObj + 1);
				MassTextBox = gcnew array< System::Windows::Forms::TextBox^ >(countObj + 1);

				MassObjLocked = gcnew array<bool^>(countObj + 1);

				InicialNewObject(countObj);

				//Увеличить число объектов на поле.
				countObj++;
			}
		}

		//Инициализация новых обектов.
		System::Void InicialNewObject(int countObj)
		{

			//Выделение памяти для нового объекта:
			MassPanel[countObj] = gcnew System::Windows::Forms::Panel();
			//MassPictureBox[countObj] = gcnew System::Windows::Forms::PictureBox();
			MassNameFactory[countObj] = gcnew System::Windows::Forms::Label();
			MassListBox[countObj] = gcnew System::Windows::Forms::ListBox();
			MassTextBox[countObj] = gcnew System::Windows::Forms::TextBox();

			MassObjLocked[countObj] = gcnew bool;

			//(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MassPictureBox[countObj]))->BeginInit();

			this->MassPanel[countObj]->SuspendLayout();
			this->SuspendLayout();


			//PictureBoxs:

			//{
			//	this->MassPictureBox[countObj]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
			//		static_cast<System::Int32>(static_cast<System::Byte>(64)),
			//		static_cast<System::Int32>(static_cast<System::Byte>(64)));
			//
			//	MassPictureBox[countObj]->Location = System::Drawing::Point(0, 0);
			//	MassPictureBox[countObj]->Name = L"pictureBox1";
			//	MassPictureBox[countObj]->Size = System::Drawing::Size(250, MassListBox[countObj]->Size.Height + 72);
			//	MassPictureBox[countObj]->TabIndex = 0;
			//	MassPictureBox[countObj]->TabStop = false;
			//
			//	MassPictureBox[countObj]->DragOver += gcnew System::Windows::Forms::DragEventHandler(this, &MyForm::pictureBox1_DragOver);
			//	MassPictureBox[countObj]->DragLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_DragLeave);
			//	MassPictureBox[countObj]->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Object_MouseDown);
			//	MassPictureBox[countObj]->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Object_MousMove);
			//}

			//panel:
			{
				MassPanel[countObj]->Controls->Add(this->MassListBox[countObj]);
				MassPanel[countObj]->Controls->Add(this->MassNameFactory[countObj]);
				MassPanel[countObj]->Controls->Add(this->MassTextBox[countObj]);
				//this->MassPanel[countObj]->Controls->Add(this->MassPictureBox[countObj]);



				MassPanel[countObj]->Location = Drawing::Point(MouseDownLocation.X - 10, MouseDownLocation.Y - 64);
				MassPanel[countObj]->Size = Drawing::Size(NormalWidthObject + 120, NormalHeightObject);

				MassPanel[countObj]->MaximumSize = Drawing::Size(120 + 30 + 101, 32 + 7 * 2 * 12.28571F + 101);
				MassPanel[countObj]->MinimumSize = Drawing::Size(80 + 30 - 50, 32 + 7 * 2 * 8.28571F - 50);

				MassPanel[countObj]->ContextMenuStrip = this->menu_Object;

				MassPanel[countObj]->TabIndex = 1;
				MassPanel[countObj]->Margin = Windows::Forms::Padding(30);

				MassPanel[countObj]->BackColor = Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
					static_cast<System::Int32>(static_cast<System::Byte>(64)),
					static_cast<System::Int32>(static_cast<System::Byte>(64)));

				MassPanel[countObj]->MouseDown += gcnew Windows::Forms::MouseEventHandler(this, &MyForm::Object_MouseDown);
				MassPanel[countObj]->MouseMove += gcnew Windows::Forms::MouseEventHandler(this, &MyForm::Object_MousMove);
				
				

				//MassPanel[countObj]->MouseEnter += gcnew System::EventHandler(this, &MyForm::Object_MousEnter);
			}

			//NameFactory:
			{
				//this->MassNameFactory[countObj]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				//	static_cast<System::Int32>(static_cast<System::Byte>(64)),
				//	static_cast<System::Int32>(static_cast<System::Byte>(64)));

				MassNameFactory[countObj]->ContextMenuStrip = this->menu_Object;
				MassNameFactory[countObj]->FlatStyle = System::Windows::Forms::FlatStyle::System;

				MassNameFactory[countObj]->Font = (gcnew System::Drawing::Font(L"Consolas", 10.28571F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
				MassNameFactory[countObj]->ForeColor = System::Drawing::SystemColors::HighlightText;

				MassNameFactory[countObj]->Location = System::Drawing::Point(0, 8);
				MassNameFactory[countObj]->Size = System::Drawing::Size(NormalWidthObject, 20);

				MassNameFactory[countObj]->MaximumSize = System::Drawing::Size(350, 20);
				MassNameFactory[countObj]->MinimumSize = System::Drawing::Size(65, 18);

				MassNameFactory[countObj]->TabIndex = 1;
				MassNameFactory[countObj]->Text = L"Фабрика";
				MassNameFactory[countObj]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

				MassNameFactory[countObj]->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Object_MouseDown);
				MassNameFactory[countObj]->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Object_MousMove);
			}

			//ListBox:
			{
				MassListBox[countObj]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));


				MassListBox[countObj]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
					static_cast<System::Int32>(static_cast<System::Byte>(50)),
					static_cast<System::Int32>(static_cast<System::Byte>(50)));

				MassListBox[countObj]->BorderStyle = System::Windows::Forms::BorderStyle::None;
				MassListBox[countObj]->ContextMenuStrip = this->menu_Res;

				MassListBox[countObj]->Font = (gcnew System::Drawing::Font(L"Consolas", ScaleFont, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
				MassListBox[countObj]->ForeColor = System::Drawing::SystemColors::MenuBar;

				MassListBox[countObj]->ItemHeight = 1;
				MassListBox[countObj]->Items->AddRange(gcnew cli::array <System::Object^>(7)
				{
					L"abc1", L"dfd4", L"fsaf2", L"sdf", L"ssss", L"ssss1", L"ssss2"
				});

				MassListBox[countObj]->Location = System::Drawing::Point(15, 32);
				MassListBox[countObj]->Size = System::Drawing::Size(100, MassListBox[countObj]->Items->Count * 2 * ScaleFont);

				MassListBox[countObj]->MaximumSize = System::Drawing::Size(120 + 100, MassListBox[countObj]->Items->Count * 2 * 12.28571F + 100);
				MassListBox[countObj]->MinimumSize = System::Drawing::Size(80 - 50, MassListBox[countObj]->Items->Count * 2 * 8.28571F - 50);


				MassListBox[countObj]->Sorted = true;
				MassListBox[countObj]->TabIndex = 2;

				MassListBox[countObj]->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Object_MouseDown);
				MassListBox[countObj]->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Object_MousMove);
			}

			//TextBox:
			{
				MassTextBox[countObj]->Text = "X: " + MassPanel[countObj]->Location.X + " Y: " + MassPanel[countObj]->Location.Y;
				MassTextBox[countObj]->Location = System::Drawing::Point(150, 40);
				MassTextBox[countObj]->Size = System::Drawing::Size(100, 20);
				MassTextBox[countObj]->TabIndex = 0;
			}

			//ObjLocked:
			{
				MassObjLocked[countObj] = false;
			}

			//(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MassPictureBox[countObj]))->EndInit();

			this->Working_area->Controls->Add(this->MassPanel[countObj]);

			this->ResumeLayout();
			this->PerformLayout();
		}

		//Удаление объектов с плоскости.												!!!Временная заглушка.
		System::Void dellObjectToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
		{
			//Удаление происходит не корректно т.к. при удалении не с хвоста и добавлении нового элемента, новый элемент затирает существующий
			//Пофиксится при использовании списков или неуменьшении счетчика объектов.

			delete MassPanel[NomberObj];
			countObj--;
		}

		//Переименование объектов.														//Еще не дописанно.
		System::Void Menu_RenameObject_Click(Object^ sender, EventArgs^ e)
		{
			RenameTextBox = gcnew TextBox;

			RenameTextBox->Location = MassNameFactory[NomberObj]->Location;
			RenameTextBox->Size = MassNameFactory[NomberObj]->Size;

			RenameTextBox->Focus();

			MassNameFactory[NomberObj]->Text = RenameTextBox->Text;
		}

		//Фиксирование объекта на плоскости.
		System::Void Menu_fixObject_Click(Object^ sender, EventArgs^ e)
		{
			if (*MassObjLocked[NomberObj] == false)
				MassObjLocked[NomberObj] = true;
			else
				MassObjLocked[NomberObj] = false;
		}

		System::Void menu_addDelivery_Click(System::Object^ sender, System::EventArgs^ e) 
		{

		}

//==========================================================================================================================

		//Фиксирование перемещения мыши на объекте.
		System::Void Object_MousMove(Object^ sender, MouseEventArgs^ e)
		{
			//textBox1->Text = "W: " + (e->X) + " H: " + (e->Y) + " X: " + MouseDownLocation.X + " Y: " + MouseDownLocation.Y + " dx:" + dx + " dy:" + dy;
			//textBox1->Text = "L: " + Touch_Left_Border + " R: " + Touch_Right_Border + " T: " + Touch_Top_Border + " D: " + Touch_Down_Border + " |||| " + Contact(NomberObj); //" CX1: " + CentralObjX + " CX2: " + CentralObjX2;
			//textBox2->Text = "L: " + BorderLeft + " R: " + BorderRight + " T: " + BorderTop + " D: " + BorderDown; //+ "DX/DY:" + Delta; //" DX: " + DeltaX + " DY: " + DeltaY;// +" |||| " + Contact(NomberObj);

			if (e->Button == Windows::Forms::MouseButtons::Left && !*MassObjLocked[NomberObj])
			{
				dx = e->X - MouseDownLocation.X;
				dy = e->Y - MouseDownLocation.Y;

				//Если объекты не соприкоснулись или касания до этого не было:
				if (!Contact(NomberObj))
				{
					MassPanel[NomberObj]->Left += dx;
					MassPanel[NomberObj]->Top += dy;
				}
				else
				{
					//Если касание сверху:
					if (Touch_Top_Border)
					{
						//Не дать подвинуть элемент вверх.
						if (dy > 0)
						{
							MassPanel[NomberObj]->Top += dy;

							//Если пересечений слева и справа нет, двагать по иксу.
							if (!Touch_Left_Border && !Touch_Right_Border)  MassPanel[NomberObj]->Left += dx;
						}
						else if (!Touch_Left_Border && !Touch_Right_Border)  MassPanel[NomberObj]->Left += dx;

					}
					
					//Если касание снизу:
					if (Touch_Down_Border)
					{
						//Не дать подвинуть вниз.
						if (dy < 0)
						{
							MassPanel[NomberObj]->Top += dy;

							if (!Touch_Left_Border && !Touch_Right_Border)  MassPanel[NomberObj]->Left += dx;
						}
						else if (!Touch_Left_Border && !Touch_Right_Border)  MassPanel[NomberObj]->Left += dx;
					}

					//Если касание слева:
					if (Touch_Left_Border)
					{
						//Не дать подвинуть влево.
						if (dx > 0)
						{
							MassPanel[NomberObj]->Left += dx;

							if (!Touch_Down_Border && !Touch_Top_Border)  MassPanel[NomberObj]->Top += dy;
						}
						else if (!Touch_Down_Border && !Touch_Top_Border)  MassPanel[NomberObj]->Top += dy;
					}

					//Если касание справа:
					if (Touch_Right_Border)
					{
						//Не дать подвинуть справа.
						if (dx < 0)
						{
							MassPanel[NomberObj]->Left += dx;

							if (!Touch_Down_Border && !Touch_Top_Border)  MassPanel[NomberObj]->Top += dy;
						}
						else if (!Touch_Down_Border && !Touch_Top_Border)  MassPanel[NomberObj]->Top += dy;
					}
				}
			}
		}

		//Фиксирование нажатия лкм на объекте.
		System::Void Object_MouseDown(Object^ sender, MouseEventArgs^ e)
		{
			if (e->Button == Windows::Forms::MouseButtons::Left || e->Button == Windows::Forms::MouseButtons::Right)
			{
				MouseDownLocation = e->Location;

				//Определение, какой объект был выбран.
				getObj(sender);
			}
		}

//==========================================================================================================================

		//Фиксирование нажатия лкм на шапке.
		System::Void Hat_MouseDown(Object^ sender, MouseEventArgs^ e)
		{
			if (e->Button == Windows::Forms::MouseButtons::Left)
			{
				MouseDownLocation = e->Location;
			}
		}

		//Перемещение окна программы вслед за мышью.
		System::Void Hat_MousMove(Object^ sender, MouseEventArgs^ e)
		{
			this->SuspendLayout();

			if (e->Button == Windows::Forms::MouseButtons::Left)
			{
				MyForm::Left += e->X - MouseDownLocation.X;
				MyForm::Top += e->Y - MouseDownLocation.Y;
			}

			this->ResumeLayout();
			this->PerformLayout();
		}

//==========================================================================================================================

		//Свертывание и развёртывание формы на экране.
		System::Void button_minimise_Click(Object^ sender, EventArgs^ e)
		{
			if (MyForm::WindowState != FormWindowState::Maximized)
			{
				FullScreen = true;
				MyForm::WindowState = FormWindowState::Maximized;
			}
			else
			{
				FullScreen = false;
				MyForm::WindowState = FormWindowState::Normal;
			}
		}

		//Завершение программы.
		System::Void button_Exit_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			this->Close();
		}

		//Сворачивание в панель управление.
		System::Void button_roll_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			this->WindowState = FormWindowState::Minimized;
		}

		//Масштабирование окна программы.
		System::Void ScaleWindow_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			this->SuspendLayout();

			int dx = this->Width + this->Left;		//Координата по Х правого нижнего угла.
			int dy = this->Height + this->Top;		//Координата по У.

			if (e->Button == Windows::Forms::MouseButtons::Left)
			{
				int dW = MousePosition.X - dx;
				int dH = MousePosition.Y - dy;

				//this->Width += MousePosition.X - dx;
				//this->Height += MousePosition.Y - dy;

				
				//delete GPath;
				//GPath = gcnew Drawing2D::GraphicsPath();
				//GPath->Reset();

				////int radius = 30;

				//GPath->AddLine(30, 0, this->Width - 30, 0);
				//GPath->AddArc(this->Width + dW - 30, 0, 30, 30, 270, 90);
				//GPath->AddLine(this->Width + dW, 30, this->Width + dW, this->Height + dH - 30);
				//GPath->AddArc(this->Width + dW - 30, this->Height + dH - 30, 30, 30, 0, 90);
				//GPath->AddLine(this->Width + dW - 30, this->Height + dH, 30, this->Height + dH);
				//GPath->AddArc(0, this->Height + dH - 30, 30, 30, 90, 90);
				//GPath->AddLine(0, this->Height +dH - 30, 0, 30);
				//GPath->AddArc(0, 0, 30, 30, 180, 90);


				//delete myRegion;
				//myRegion = gcnew Drawing::Region(GPath);
				//// устанавливаем видимую область,
				//this->Region = myRegion;

				this->Width += dW;
				this->Height += dH;
			}

			this->ResumeLayout();
			this->PerformLayout();
		}

//==========================================================================================================================

		//Фиксирование координат нажатия мыши.
		System::Void Working_area_MouseDown(Object^ sender, MouseEventArgs^ e)
		{
			if (e->Button == Windows::Forms::MouseButtons::Left || e->Button == Windows::Forms::MouseButtons::Right)
			{
				MouseDownLocation = e->Location;
			}
		}

		//Освобождение памяти от координат всех объектов.
		System::Void Working_area_MouseUp(Object^ sender, MouseEventArgs^ e)
		{/*
			delete[] LastPosX;
			delete[] LastPosY;*/
		}

		//Перемещение объкетов по экрану.
		System::Void WorkingArea_MouseMove(Object^ sender, MouseEventArgs^ e)
		{
			textBox1->Text = "W: " + (e->Location.X) + " H: " + (e->Location.Y) + " X: " + MouseDownLocation.X + " Y: " + MouseDownLocation.Y + " CountMove: " + Experiment++;
			
			Working_area->SuspendLayout();

			if (e->Button == Windows::Forms::MouseButtons::Left && MassPanel != nullptr)
			{

				float dx = (this->Cursor->Position.X - MouseDownLocation.X - this->Location.X);
				float dy = (this->Cursor->Position.Y - MouseDownLocation.Y - this->Location.Y);

				Working_area->Left = (dx);
				Working_area->Top = (dy);
			}
		
			Working_area->ResumeLayout();
			Working_area->PerformLayout();
		}

		//Фиксирование всех объектов на плоскости.
		System::Void MenuPlane_fixAllObj_Click(Object^ sender, EventArgs^ e)
		{
			if (AllObjLocked == false)
			{
				for (int i = 0; i < countObj; i++)
					MassObjLocked[i] = true;

				AllObjLocked = true;
			}
			else
			{
				for (int i = 0; i < countObj; i++)
					MassObjLocked[i] = false;

				AllObjLocked = false;
			}
		}

//==========================================================================================================================

		System::Void MyZoom(float dx, MouseEventArgs^ e)
		{
			//System::Drawing::SizeF oldSize;

			for (int i = 0; i < countObj; i++)
			{
				this->MassPanel[i]->SuspendLayout();
				this->SuspendLayout();


				//Если размер панели меньше максимального и больше минимального.
				if (MassPanel[i]->Size.Height > MassPanel[i]->MinimumSize.Height && MassPanel[i]->Size.Height < MassPanel[i]->MaximumSize.Height)
				{
					//Скейлинг шрифта:
					if (e->Delta > 0)							//Эффект отдаления (Объекты уменьшаются и приближаются к мыши)
					{
						if (ScaleFont > 8.28571F)
							ScaleFont *= (0.9);
						else                                    //Заменить на иф!!
							ScaleFont = 8.28571F + 0.0001;

						//if (ScaleFont > 12.28571F)
						//{
						//	ScaleFont = 12.28571F - 0.0001;
						//}
					}
					else if (e->Delta < 0)						//Эффект приближения (Объекты увелчиваются и отдаляются от мыши)
					{
						if (ScaleFont < 12.28571F)
							ScaleFont *= (1.1);
						else                                    //Заменить на иф!!
							ScaleFont = 12.28571F - 0.0001;

						//if (ScaleFont < 8.28571F)
						//{
						//	ScaleFont = 8.28571F + 0.0001;
						//}
					}

					//IndScale = NormalHeightObject / MassPanel[i]->Size.Height;

					//Изменение размеров объектов.
					ResizeMyObj(i, dx, e);

					//Перемещение объектов относительно мыши.
					MyMousePosition(i, dx, e);
				}
				//Если размер панели меньше минимального и картинка зумится+.								//Срабатывают редко, но +60 строк.
				else if (MassPanel[i]->Size.Height <= MassPanel[i]->MinimumSize.Height && dx > 1)
				{
					ScaleFont *= (1.1);

					ResizeMyObj(i, dx, e);

					//Перемещение объектов относительно мыши.
					MyMousePosition(i, dx, e);
				}
				//Если размер панели больше максимального и картинка зумится-.   
				else if (MassPanel[i]->Size.Height >= MassPanel[i]->MaximumSize.Height && dx < 1)
				{
					ScaleFont *= (0.9);

					ResizeMyObj(i, dx, e);

					//Перемещение объектов относительно мыши.
					MyMousePosition(i, dx, e);
				}

				MassTextBox[i]->Text = "X: " + MassPanel[i]->Location.X + " Y: " + MassPanel[i]->Location.Y;

				this->ResumeLayout(false);
				this->PerformLayout();
			}
		}

		System::Void MyMousePosition(int i, float dx, MouseEventArgs^ e)
		{
			textBox2->Text = "X: " + CentralObjX + "Delta: " + (e->X - MassPanel[i]->Location.X) / 5;

			Working_area->SuspendLayout();

			CentralObjX = MassPanel[i]->Location.X + MassPanel[i]->Size.Width / 2;
			CentralObjY = MassPanel[i]->Location.Y + MassPanel[i]->Size.Height / 2;

			//Если (отдаление и курсор левее Центра Объекта) или (приближение и курсор правее Ц.О.):
			if ((e->Delta < 0 && e->X > CentralObjX) || (e->Delta < 0 && e->X < CentralObjX))
			{
				MassPanel[i]->Left = MassPanel[i]->Left - (e->X - CentralObjX) / 5;
				MassPanel[i]->Top = MassPanel[i]->Top - (e->Y - CentralObjY) / 5;
			}
			//Иначе (приближение и курсор левее Ц.О.) или (отдаление и курсор правее Ц.О.).
			else
			{
				MassPanel[i]->Left = MassPanel[i]->Left + (e->X - CentralObjX) / 6;
				MassPanel[i]->Top = MassPanel[i]->Top + (e->Y - CentralObjY) / 6;
			}

			/*
				if (e->X > MassPanel[i]->Location.X + MassPanel[i]->Size.Width/2)						// Если мышь находится справа от объекта.
					if (e->Delta < 0)																	//Отдаление от мыши, координата х уменьшается
					{
						//Point point(MassPanel[i]->Left - (e->X - MassPanel[i]->Location.X )/100*10, MassPanel[i]->Top - (e->Y - MassPanel[i]->Location.Y ) / 100 * 10);
						//MassPanel[i]->Location = Drawing::Point(point);

						MassPanel[i]->Left = MassPanel[i]->Left - (e->X - MassPanel[i]->Location.X) / 100 * 10;
						MassPanel[i]->Top = MassPanel[i]->Top - (e->Y - MassPanel[i]->Location.Y) / 100 * 10;
					}
					else																				//Отдаление от мыши, координата х увеличивается.
					{
						//Point point(MassPanel[i]->Left + (e->X - MassPanel[i]->Location.X) / 100 * 10, MassPanel[i]->Top + (e->Y - MassPanel[i]->Location.Y) / 100 * 10);
						//MassPanel[i]->Location = Drawing::Point(point);

						MassPanel[i]->Left = MassPanel[i]->Left + (e->X - MassPanel[i]->Location.X) / 100 * 10;
						MassPanel[i]->Top = MassPanel[i]->Top + (e->Y - MassPanel[i]->Location.Y) / 100 * 10;
					}

				else																					// Если мышь находится слева от объекта.
				{
					if (e->Delta < 0)																	//Отдаление от мыши, координата х увеличивается.
					{
						MassPanel[i]->Left = MassPanel[i]->Left - (e->X - MassPanel[i]->Left) / 100 * 10;
						MassPanel[i]->Top = MassPanel[i]->Top - (e->Y - MassPanel[i]->Top) / 100 * 10;
					}
					else																				//Приближение к мыши, координата х уменьшается.
					{
						MassPanel[i]->Left = MassPanel[i]->Left + (e->X - MassPanel[i]->Left) / 100 * 10;
						MassPanel[i]->Top = MassPanel[i]->Top + (e->Y - MassPanel[i]->Top) / 100 * 10;
					}
				}
			*/


			Working_area->ResumeLayout();
			Working_area->PerformLayout();
		}

		System::Void ResizeMyObj(int i, float dx, MouseEventArgs^ e)
		{
			Working_area->SuspendLayout();

			//Координаты центра объектов до их масштабирования.
			CentralObjX = MassPanel[i]->Location.X + MassPanel[i]->Size.Width / 2;
			CentralObjY = MassPanel[i]->Location.Y + MassPanel[i]->Size.Height / 2;

			//Задаём новый размер панелей.
			MassPanel[i]->Size = System::Drawing::Size(MassPanel[i]->Size.Width * dx, MassPanel[i]->Size.Height * dx);

			//Двигаем панель так, чтобы при изменении размеров панелей координаты центра не изменялись.
			MassPanel[i]->Left = CentralObjX - MassPanel[i]->Size.Width / 2;
			MassPanel[i]->Top = CentralObjY - MassPanel[i]->Size.Height / 2;

			/*MassNameFactory[i]->Size = System::Drawing::Size(MassNameFactory[i]->Size.Width * dx, MassNameFactory[i]->Size.Height * dx);

			delete[] MassNameFactory[i]->Font;

			MassNameFactory[i]->Font = (gcnew System::Drawing::Font(L"Consolas", ScaleFont, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));*/

			/*MassListBox[i]->Size = System::Drawing::Size(MassListBox[i]->Size.Width * dx, MassListBox[i]->Size.Height * dx);

			//delete[] MassListBox[i]->Font;

			//MassListBox[i]->Font = (gcnew System::Drawing::Font(L"Consolas", ScaleFont, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));*/


			Working_area->ResumeLayout();
			Working_area->PerformLayout();
		}

//==========================================================================================================================

		//Определение, какой объект был выбран.
		System::Void getObj(Object^ sender)
		{
			int i = 0;

			while (!Flag)
			{
				if ((MassListBox[i]->Equals(sender)) || (MassPanel[i]->Equals(sender)) || (MassNameFactory[i]->Equals(sender)))
				{
					NomberObj = i;
					Flag = true;
					CurrentObj = sender;
				}

				i++;
			}
			Flag = false;
		}

		//Функция проверки пересечений объектов.
		System::Boolean Contact(int NomberMoveObj)
		{
			int LowLeftCorner = MassPanel[NomberMoveObj]->Top + MassPanel[NomberMoveObj]->Height;		//Левый нижний угол перемещаемого объекта		(П.О.).
			int TopRightCorner = MassPanel[NomberMoveObj]->Left + MassPanel[NomberMoveObj]->Width;		//Правый верхний угол перемещаемого объекта		(П.О.).

			int LowLeftCorneri;																			//Левый нижний угол соприкасаемого объекта		(С.О.).
			int TopRightCorneri;																		//Правый верхний угол соприкасаемого объекта	(С.О.).

			bool Touch_Top = false;
			bool Touch_Down = false;
			bool Touch_Left = false;
			bool Touch_Right = false;


			for (int i = 0; i < MassPanel->Length; i++)
			{
				if (i != NomberMoveObj)
				{
					CentralObjX = MassPanel[NomberMoveObj]->Left + MassPanel[NomberMoveObj]->Width / 2;			//Центр перетаскиваемого объекта.
					CentralObjY = MassPanel[NomberMoveObj]->Top + MassPanel[NomberMoveObj]->Height / 2;

					CentralObjX2 = MassPanel[i]->Left + MassPanel[i]->Width / 2;								//Центр соприкасаемого объекта.
					CentralObjY2 = MassPanel[i]->Top + MassPanel[i]->Height / 2;

					///Расчет центров будет отсюда удалён, останется только расчет центра перетасиваемого объекта.

					//Расчет разниц между центрами.
					if (CentralObjX2 > CentralObjX)
					{
						DeltaX = CentralObjX2 - CentralObjX;
					}
					else
						DeltaX = CentralObjX - CentralObjX2;

					if (CentralObjY2 > CentralObjY)
					{
						DeltaY = CentralObjY2 - CentralObjY;
					}
					else
						DeltaY = CentralObjY - CentralObjY2;

					//Если расстояние между центрами достаточно близкое, то проверить на столкновение.
					if (DeltaX < (150 + MassPanel[i]->Width) && DeltaY < (150 + MassPanel[i]->Height))
					{
						LowLeftCorneri = MassPanel[i]->Top + MassPanel[i]->Height;
						TopRightCorneri = MassPanel[i]->Left + MassPanel[i]->Width;

						//Проверка, с какой стороны было касание.
						{
							//Если левая и правая части перетаскиваемого объекта (П.О.) ЛЕВЕЕ частей соприкасаемого объекта (С.О.).
							if (MassPanel[NomberMoveObj]->Left <= MassPanel[i]->Left - margin && MassPanel[i]->Left - margin <= TopRightCorner)
							{
								BorderRight = true;			//То считать, что перетаскиваемый объект столкнулся правым бортом.
							}
							else
								BorderRight = false;


							//Если левая и правая			  --//--			 ПРАВЕЕ			--//-- .
							if (MassPanel[NomberMoveObj]->Left <= TopRightCorneri + margin && TopRightCorneri + margin <= TopRightCorner)  			//Есди удар справа.
							{
								BorderLeft = true;
							}
							else
								BorderLeft = false;


							//Если верхняя и нижняя			  --//--			  ВЫШЕ			--//-- .
							if (LowLeftCorner >= MassPanel[i]->Top - margin && MassPanel[i]->Top - margin >= MassPanel[NomberMoveObj]->Top)			//Если удар сверху.
							{
								BorderDown = true;
							}
							else
								BorderDown = false;


							//Если верхняя и нижняя			  --//--			  НИЖЕ			--//-- .
							if (MassPanel[NomberMoveObj]->Top <= LowLeftCorneri + margin && LowLeftCorneri + margin <= LowLeftCorner)				//Если удар снизу.
							{
								BorderTop = true;
							}
							else
								BorderTop = false;
						}

						//!! убрать динамический расчет диагоналей эл-тов.
						float DiagonalAngel = (MassPanel[i]->Width / 2) / static_cast<float>(MassPanel[i]->Height / 2);		//Угол диагонали объекта, с которым происходит касание.

						//Оставить
						float Angel = DeltaX / static_cast<float>(DeltaY);									//Угол между двумя объектами.

						//Подводим итоги.
						if (Angel < DiagonalAngel)
						{
							if (BorderTop)
								Touch_Top = true;

							if (BorderDown)
								Touch_Down = true;
						}
						else if (Angel > DiagonalAngel)
						{
							if (BorderLeft)
								Touch_Left = true;

							if (BorderRight)
								Touch_Right = true;
						}

					}
				}
			}

			//Если касание было.
			if (Touch_Right || Touch_Left || Touch_Down || Touch_Top)
			{
				//Подводим итоги.

				if (Touch_Top)
					Touch_Top_Border = true;
				else
					Touch_Top_Border = false;

				if (Touch_Down)
					Touch_Down_Border = true;
				else
					Touch_Down_Border = false;

				if (Touch_Left)
					Touch_Left_Border = true;
				else
					Touch_Left_Border = false;

				if (Touch_Right)
					Touch_Right_Border = true;
				else
					Touch_Right_Border = false;

				return true;																			//Подтверждаем касание.
			}
			else
			{
				Touch_Left_Border = false;
				Touch_Right_Border = false;
				Touch_Top_Border = false;
				Touch_Down_Border = false;

				return false;
			}
		}

		void OnMouseWheel(System::Object^ sender, MouseEventArgs^ e);


		System::Void ShowDelivery(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) 
		{
			textBox2->Text = sender->GetType()->ToString();
		}
		private: System::Void dataGridView1_RowHeaderMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) 
		{
			textBox2->Text = sender->GetType()->ToString();
		}
};
}

void Project1::MyForm::OnMouseWheel(Object^ sender, MouseEventArgs^ e)
{
	float ZoomMinX = 0.8197, ZoomPlusX = 1.22; //ZoomPlusY = 1.033;  ZoomMinY = 0.88,

	//Колёсико вверх.
	if (e->Delta > 0 && MassPanel != nullptr)
	{
		if (MassPanel[0]->Size.Width > MassPanel[0]->MinimumSize.Width) MyZoom(ZoomMinX, e); //Working_area->Scale(ZoomMinX);
	}
	//Колёсико вниз.
	else if (e->Delta < 0 && MassPanel != nullptr)
	{
		if (MassPanel[0]->Size.Width < MassPanel[0]->MaximumSize.Width) MyZoom(ZoomPlusX, e); //Working_area->Scale(ZoomPlusX);
	}
}

template <class T>
void Project1::MyForm::setNewReg(T^ obj, int radius)
{
	//obj->CreateGraphics()->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
	//obj->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

	Drawing2D::GraphicsPath^ GPath;
	Drawing::Region^ myRegion;

	GPath = gcnew Drawing2D::GraphicsPath();

	GPath->AddLine(radius, 0, obj->Width - radius, 0);
	GPath->AddArc(obj->Width - radius, 0, radius, radius, 270, 90);
	GPath->AddLine(obj->Width, radius, obj->Width, obj->Height - radius);
	GPath->AddArc(obj->Width - radius, obj->Height - radius, radius, radius, 0, 90);
	GPath->AddLine(obj->Width - radius, obj->Height, radius, obj->Height);
	GPath->AddArc(0, obj->Height - radius, radius, radius, 90, 90);
	GPath->AddLine(0, obj->Height - radius, 0, radius);
	GPath->AddArc(0, 0, radius, radius, 180, 90);

	// создаем с помощью элипса ту область формы, которую мы хотим видеть
	myRegion = gcnew Drawing::Region(GPath);
	// устанавливаем видимую область
	obj->Region = myRegion;

	obj->CreateGraphics()->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
}