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
                    serialPort = new SerialPort("COM3", 57600);      //Common baud rate of 9600
                    serialPort.ReadTimeout = (2000);
                    serialPort.WriteTimeout = (2000);
                    serialPort.Open();
                } catch (Exception ex)
                {
                    MessageBox.Show("Exception happened ...... !" + ex);
                }
                
            }
        }

        private void cmdExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Degree_0_Click(object sender, EventArgs e)
        {
            try
            {
                //serialPort.Open();
                serialPort.Write("1");          //For 0 Degree movement of servo
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Degree_45_Click(object sender, EventArgs e)
        {
            try
            {
                //serialPort.Open();
                serialPort.Write("2");          //For 0 Degree movement of servo
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Degree_90_Click(object sender, EventArgs e)
        {
            try
            {
                //serialPort.Open();
                serialPort.Write("3");          //For 0 Degree movement of servo
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Degree_135_Click(object sender, EventArgs e)
        {
            try
            {
                //serialPort.Open();
                serialPort.Write("4");          //For 0 Degree movement of servo
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Degree_180_Click(object sender, EventArgs e)
        {
            try
            {
                //serialPort.Open();
                serialPort.Write("5");          //For 0 Degree movement of servo
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }//End of main class
}//End of namespace
