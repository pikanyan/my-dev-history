using System.Collections.ObjectModel;
using System.Windows;

namespace WPF
{
    public class BlockViewModel
    {
        public ObservableCollection<BlockModel> BlockModels { get; private set; }

        public int ColumnNum { get; } = 10;
        public int RowNum { get; } = 6;



        public BlockViewModel()
        {
            BlockModels = new ObservableCollection<BlockModel>();

            Initialize_BlockModels();
        }



        private void Initialize_BlockModels()
        {
            for (int row = 0; row < RowNum; row++)
            {
                for(int column = 0; column < ColumnNum; column++)
                {
                    BlockModels.Add(new BlockModel
                    {
                        Left = 10 + 30 * column,
                        Top = 40 + 10 * row,
                    });
                }
            }
        }
    }
}
