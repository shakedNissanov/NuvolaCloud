   M S B A M L   `   `   `  ����  	NuvolaWPF)    #NuvolaWPF.Pages.Files.UploadedFiles   5      R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      Z VFirstFloor.ModernUI, Version=1.0.9.0, Culture=neutral, PublicKeyToken=bc9b0c37bf06c6a90mui&http://firstfloorsoftware.com/ModernUI  5      -   5        .��5	      �    ContentRoot#��[  6   .+�5
   
   �� .��5      &   System.Windows.Controls.DataGrid  -   5        $��dataGrid��5          CanUserAddRows  .     CanUserSortColumns .    SelectionMode$ Single=�6      AutoGenerateColumns .  $��Stretch=�5   ,   $��Stretch=�6J      
IsReadOnly . $��24(�6x   ��5   )   �� *ItemBinding+   ColumnHeaderStyle 5      �� 5       �� 
TargetType=  7System.Windows.Controls.Primitives.DataGridColumnHeader"  6   .�5      ��  �� Property � �� �� Value$ 24(�65   5      	   Columns	 5      0  *System.Windows.Controls.DataGridTextColumn  5      ,  &System.Windows.Controls.DataGridColumn
   Header$

 Name��6)      Width5  /System.Windows.Controls.DataGridLengthConverter$ 1* 6W      FontSize$ 20Q�6b   1  +System.Windows.Controls.DataGridBoundColumn   Binding 69   ��  �� Path$
 name�6b     5      $

 Type��6)   $ 1* 6W   $ 20Q�6b    69   �� $
 type�6b     5      $

 User��6)   $ 1* 6W   $ 20Q�6b    69   �� $
 user�6b     5      $
 	Size [KB]��6)   $ 1* 6\   $ 20Q�6g    6>   �� $
 size�6g     5      $
 Is Encrypted��6)   $ 1* 6d   $ 20Q�6o    6A   �� $ 	encrypted�6o   4  .System.Windows.Controls.DataGridTemplateColumn  5      $
 Retrieve��6-   $ 1* 6?      CellTemplate 5      �� 5      .R�5   "   �� -   5        .��5   >   
Retrieve6H   5      5       5#      5$      5%      5&      