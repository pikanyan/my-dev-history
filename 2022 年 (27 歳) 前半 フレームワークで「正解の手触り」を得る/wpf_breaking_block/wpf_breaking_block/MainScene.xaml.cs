using System;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Threading;
using System.Windows.Media.Media3D;

namespace WPF
{
    public partial class MainScene : UserControl
    {
        private DispatcherTimer _timer;   // 追加
        private double _t;                // 追加

        public MainScene()
        {
            InitializeComponent();
        }

        // 追加: ゲーム開始（まず “動いてる” を確認する用）
        public void Start()
        {
            if (_timer != null) return; // 二重起動防止

            _timer = new DispatcherTimer
            {
                Interval = TimeSpan.FromMilliseconds(16) // 約60fps
            };

            _timer.Tick += (_, __) =>
            {
                _t += 1;

                // 追加: Block を少し動かして、更新ループが生きてるのを確認
                BlockControl.RenderTransform = new TranslateTransform((_t % 120), 0);
            };

            _timer.Start();
        }
    }
}
