# If you come from bash you might have to change your $PATH.

export ZSH=/opt-src/oh-my-zsh
source $ZSH/oh-my-zsh.sh

export PROMPT='${ret_status} %m %{$fg_bold[green]%}%p %{$fg[cyan]%}%c %{$fg_bold[blue]%}$(git_prompt_info)%{$fg_bold[blue]%} %D %t % %{$reset_color%}'

export LC_CTYPE=en_US.UTF-8

# paths 
export PATH=$PATH:$HOME/.local/bin/

export OPTDIR=/opt
export PATH=$OPTDIR/Xilinx/Vivado/2018.3/bin:$PATH
export PATH=$OPTDIR/altera18.1/modelsim_ase/bin:$PATH
