function open_exe(strPath)
{
    try{
        //新建一个ActiveXObject对象
        a = new   ActiveXObject("wscript.shell");
        a.run(strPath);
    }catch(e)
    {
        alert('请使用IE内核浏览器打开该页面');
    }
}