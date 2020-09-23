using System;
using System.IO.Ports;
using System.Windows.Forms;

namespace Arduino_Serial
{
    public partial class Form1 : Form
    {
        SerialPort serialPort;      //Define the main serial port object
        //Main form initialization only
        public Form1()
        {
            InitializeComponent();
            if (serialPort == null)
            {
                try
                {
                    serialPort = new SerialPort("COM3", 9600);      //Common baud rate of 9600
                    serialPort.Open();
                } catch (Exception ex)
                {
                    MessageBox.Show("Exception happened ...... !" + ex);
                }
                
            }
        }

        private void btnOn_Click(object sender, EventArgs e)
        {
            serialPort.Write("1");
        }

        private void btnOff_Click(object sender, EventArgs e)
        {
            serialPort.Write("2");
        }

        private void Degree_135_Click(object sender, EventArgs e)
        {
            serialPort.Write("3");
        }

        private void Degree_180_Click(object sender, EventArgs e)
        {
            serialPort.Write("4");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort.Write("5");
        }
    }//End of main class
}//End of namespace
