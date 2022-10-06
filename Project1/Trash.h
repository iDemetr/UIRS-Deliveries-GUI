#pragma once


//Диагонали на объекте.
System::Void Object_Paintt(Object^ sender, PaintEventArgs^ e)
{
	Graphics^ gr1 = e->Graphics;
	Pen^ pp = gcnew Pen(Color::Blue, 5);// цвет линии и ширина

	int x11, x22, y11, y22;

	x11 = 0;
	x22 = MassPanel[0]->Width;
	y11 = 0;
	y22 = MassPanel[0]->Height;


	gr1->DrawLine(pp, x11, y11, x22, y22);
	gr1->DrawLine(pp, x11, y22, x22, y11); // рисуем линию


	delete gr1;
	//gr->Dispose();// освобождаем все ресурсы, связанные с отрисовкой
}


MassPanel[countObj]->Paint += gcnew Windows::Forms::PaintEventHandler(this, &MyForm::Object_Paintt);

//Диагонали на объекте.
	private: System::Void Object_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		if (MassPanel != nullptr)
		{

			System::Drawing::Drawing2D::GraphicsPath^ path = gcnew System::Drawing::Drawing2D::GraphicsPath();
			Graphics^ gr = e->Graphics;
			Graphics^ gr2 = e->Graphics;

			Pen^ p = gcnew Pen(Color::Blue, 5);// цвет линии и ширина

			int x1, x2, y1, y2;

			x1 = MassPanel[0]->Left - 70;
			x2 = MassPanel[0]->Left + MassPanel[0]->Width + 70;
			y1 = MassPanel[0]->Top - 50;
			y2 = MassPanel[0]->Top + MassPanel[0]->Height + 50;

			gr->DrawLine(p, x1, y1, x2, y2);
			gr2->DrawLine(p, x1, y2, x2, y1);

			//Working_area->Refresh();
			//Working_area->Update();
			delete gr, gr2;

		}

	}


/*
					//Если касание было по левому борту:
					if (Touch_Left_Border)
					{
						if (dx > 0)
						{
							MassPanel[NomberObj]->Left += dx;
							MassPanel[NomberObj]->Top += dy;
						}
						else //if(BorderLeft)
						{
							MassPanel[NomberObj]->Top += dy;
						}
					}

					//Если касание было по правому борту:
					if (Touch_Right_Border)
					{
						if (dx < 0)
						{
							MassPanel[NomberObj]->Left += dx;
							MassPanel[NomberObj]->Top += dy;
						}
						else //if (BorderRight)
						{
							MassPanel[NomberObj]->Top += dy;
						}
					}

					//Если касание было по верхнему борту:
					if (Touch_Top_Border)
					{
						if (dy > 0)
						{
							MassPanel[NomberObj]->Left += dx;
							MassPanel[NomberObj]->Top += dy;
						}
						else //if (BorderTop)
						{
							MassPanel[NomberObj]->Left += dx;
						}
					}

					//Если касание было по нижнему борту:
					if (Touch_Down_Border)
					{
						if (dy < 0)
						{
							MassPanel[NomberObj]->Left += dx;
							MassPanel[NomberObj]->Top += dy;
						}
						else //if (BorderDown)
						{
							MassPanel[NomberObj]->Left += dx;
						}
					}
					*/

/*
			System::Void 1111Workasding_area_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
			{

				textBox1->Text = "W: " + (e->X) + " H: " + (e->Y) + " X: " + MouseDownLocation.X + " Y: " + MouseDownLocation.Y;



				if (e->Button == Windows::Forms::MouseButtons::Left)
				{
					int NewW = Working_area->Width + (Working_area->Left + e->X - MouseDownLocation.X);
					int NewH = Working_area->Height + (Working_area->Top + e->Y - MouseDownLocation.X);

					textBox1->Text = "W: " + (e->X) + " H: " + (e->Y) + " X: " + MouseDownLocation.X + " Y: " + MouseDownLocation.Y;


					Drawing::Size* NewSize = new Drawing::Size(NewW, NewH);

					Working_area->Width = NewSize->Width;
					Working_area->Height = NewSize->Height;



					Working_area->Left += e->X - MouseDownLocation.X;
					Working_area->Top += e->Y - MouseDownLocation.Y;

					for (int i = 0; i < countObj; i++)
					{
						MousePosition.X - this->Location.X
						MassPanel[0]->Left = MassPanel[0]->Location.X + e->X - MouseDownLocation.X;
						MassPanel[0]->Top = MassPanel[0]->Location.Y + e->Y - MouseDownLocation.Y;
					}

					Move_area(e);

					Working_area->MouseWheel
					Point* pos = gcnew Point(Cursor->Position.X - e->X, Cursor->Position.Y - e->Y);
					Working_area->Size = gcnew Point(100, 100);

					Working_area->Size.Height = 100;

					Working_area->Refresh();



					Working_area->Size = new Drawing::Size(200, 200);
					Working_area->Size->Width += 100;
					Working_area->Size.Height += 100;
				}

			}
			*/

//Перемещение всех объектов поштучно, обращаясь в координате каждой панели. (Глючно, но жизнеспособно).			
/*System::Void MouseMoveV1(System::Windows::Forms::MouseEventArgs^ e)
			{
				textBox1->Text = "W: " + (e->X) + " H: " + (e->Y) + " X: " + MouseDownLocation.X + " Y: " + MouseDownLocation.Y + " Experiment: " + Experiment++;

				if (e->Button == Windows::Forms::MouseButtons::Left && MassPanel != nullptr)
				{
					//this->MassPanel->Suspe->SuspendLayout();
					//this->SuspendLayout();

					for (int i = 0; i < countObj; i++)
					{
						this->MassPanel[i]->SuspendLayout();
						this->SuspendLayout();

						MassTextBox[i]->Text = " X: " + MassPanel[i]->Location.X + " Y: " + MassPanel[i]->Location.Y;

						MassPanel[i]->Left = LastPosX[i] + (e->X - MouseDownLocation.X) / 5;
						MassPanel[i]->Top = LastPosY[i] + (e->Y - MouseDownLocation.Y) / 5;

					}

					this->ResumeLayout(false);
					this->PerformLayout();
				}
			}*/


			//System::Void OnResize(System.EventArgs e)
			//{
			//	base.OnResize(e);
			//
			//	foreach(Control cnt in this.Controls)
			//		ResizeAll(cnt, base.Size);
			//
			//	oldSize = base.Size;
			//}

			//System::Void ResizeAll(Control control, System::Drawing::SizeF newSize)
			//{
			//	int width = newSize.Width - oldSize.Width;
			//	control.Left += (control.Left * width) / oldSize.Width;
			//	control.Width += (control.Width * width) / oldSize.Width;
			//
			//	int height = newSize.Height - oldSize.Height;
			//	control.Top += (control.Top * height) / oldSize.Height;
			//	control.Height += (control.Height * height) / oldSize.Height;
			//}

			//void OnKeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
			//void OnMouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

//
//void Project1::MyForm::OnKeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
//{
//	//throw gcnew System::NotImplementedException();
//
//
//}
//
