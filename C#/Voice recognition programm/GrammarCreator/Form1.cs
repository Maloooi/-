using System.Windows.Forms;

namespace GrammarCreator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            label1.Text = "";
        }

        FileStream _file;
        string _filename;
        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.Length > 0)
            {
                _file = File.Create(textBox1.Text + ".txt");
                _filename = _file.Name;
                label1.Text = _file.Name + " создан";
                _file.Close();
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                _filename = openFileDialog1.FileName;
                label1.Text = openFileDialog1.FileName + " открыт";
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string word = textBox1.Text;
            using (StreamWriter _writer = new StreamWriter(_filename, true))
            {
                _writer.WriteLine(word);
            }
            label1.Text = "Слово " + word + " добавлено в словарь";
        }
    }
}