using System;
using System.IO.Ports;
using System.Windows.Forms;

namespace Arduino_Serial
{
    public partial class Form1 : Form
    {
        SerialPort serialPort;      //Define the main serial port object
        static bool _continue;
        
        //Main form initialization only
        public Form1()
        {
            InitializeComponent();
            if (serialPort == null)
            {
                serialPort = new SerialPort("COM3", 9600);      //Common baud rate of 9600
                serialPort.Open();
                _continue = true;
            }
        }

        //Main click button to receive and dispaly data
        private void button1_Click(object sender, EventArgs e)
        {
            if (serialPort != null)
            {
                while (_continue)
                {
                    int calibration = 0;
                    calibration = Int32.Parse(serialPort.ReadLine()) / 10;
                    textBox1.Text = (calibration * 10).ToString();
                    pBar.Value = calibration;
                }
            } else
            {
                Application.Exit(); //End the application
            }
        }
    }//End of main class
}//End of namespace
