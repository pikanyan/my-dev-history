using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;
using System.Diagnostics;
using System.IO;



namespace _20_CursorChaser
{
    public partial class MainWindow : Window
    {
        BitmapImage imgRun = new BitmapImage();
        BitmapImage imgStay = new BitmapImage();

        double rangeMouseOver = 10.0;
        double speed = 10.0; //speed px per 10ms

        System.Drawing.Point posCharacter = new System.Drawing.Point();
        System.Drawing.Point posCursor = new System.Drawing.Point();

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Window_Initialized(object sender, EventArgs e)
        {
            initializeTimer();
            initializePosition();

            loadImage();
        }

        public void initializeTimer()
        {
            Timer timer = new Timer();
            timer.Interval = 10;
            timer.Tick += new EventHandler(eventTimer);
            timer.Enabled = true;
        }

        public void initializePosition()
        {
            posCursor = System.Windows.Forms.Cursor.Position;
            posCharacter = new System.Drawing.Point(posCursor.X - 50, posCursor.Y - 50);

            this.Left = posCharacter.X;
            this.Top = posCharacter.Y;
        }

        public void loadImage()
        {
            using (FileStream stream = File.OpenRead(@"run.png"))
            {
                imgRun.BeginInit();

                imgRun.CacheOption = BitmapCacheOption.OnLoad;
                imgRun.StreamSource = stream;

                imgRun.EndInit();
                stream.Close();
            }

            using (FileStream stream = File.OpenRead(@"stay.png"))
            {
                imgStay.BeginInit();

                imgStay.CacheOption = BitmapCacheOption.OnLoad;
                imgStay.StreamSource = stream;

                imgStay.EndInit();
                stream.Close();
            }

            this.cat.Source = imgStay;
        }

        void eventTimer(object sender, EventArgs e)
        {
            posCursor = System.Windows.Forms.Cursor.Position;

            double angle = Math.Atan2
            (
                posCursor.Y - posCharacter.Y,
                posCursor.X - posCharacter.X
            );

            posCharacter.X += (int)(speed * Math.Cos(angle));
            posCharacter.Y += (int)(speed * Math.Sin(angle));

            this.Left = posCharacter.X - 50;
            this.Top = posCharacter.Y - 50;



            if (isMousedOver())
            {
                speed = 0;

                this.cat.Source = imgStay;
            }
            else
            {
                speed = 10.0;

                this.cat.Source = imgRun;
            }
                
            setDirection();
        }

        public bool isMousedOver()
        {
            if (posCursor.X < posCharacter.X - rangeMouseOver / 2)
                return false;
            if (posCursor.X > posCharacter.X + rangeMouseOver / 2)
                return false;
            if (posCursor.Y < posCharacter.Y - rangeMouseOver / 2)
                return false;
            if (posCursor.Y > posCharacter.Y + rangeMouseOver / 2)
                return false;

            return true;
        }

        public void setDirection()
        {
            var tfg = new TransformGroup();

            this.cat.RenderTransformOrigin = new Point(0.5, 0.5);

            if (posCursor.X < posCharacter.X)
                tfg.Children.Add(new ScaleTransform(-1.0F, 1.0F)); 
            else
                tfg.Children.Add(new ScaleTransform(1.0F, 1.0F));

            this.cat.RenderTransform = tfg;
        }

        private void OnClick_Quit(object sender, RoutedEventArgs e)
        {
            Close();
        }
    }
}
