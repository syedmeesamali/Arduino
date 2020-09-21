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
                serialPort = new SerialPort("COM5", 9600);      //Common baud rate of 9600
                serialPort.Open();
            }
        }

        //Main click button to receive and dispaly data
        private void button1_Click(object sender, EventArgs e)
        {
            string valToSend;
            if (textBox1.Text == "")
            {
                textBox1.Text = "0";
            } else
            {
                valToSend = textBox1.Text;
                serialPort.Write(valToSend);
            }
            
        }
    }//End of main class
}//End of namespace
